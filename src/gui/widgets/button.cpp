/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
 *  Copyright (C) 2011-2012  The ManaPlus Developers
 *
 *  This file is part of The ManaPlus Client.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gui/widgets/button.h"

#include "client.h"
#include "configuration.h"
#include "graphics.h"
#include "graphicsvertexes.h"
#include "keydata.h"
#include "keyevent.h"
#include "logger.h"

#include "gui/palette.h"
#include "gui/theme.h"

#include "resources/imageset.h"

#include "utils/dtor.h"

#include <guichan/exception.hpp>
#include <guichan/font.hpp>

#include "debug.h"

int Button::mInstances = 0;
float Button::mAlpha = 1.0;

enum
{
    BUTTON_STANDARD = 0, // 0
    BUTTON_HIGHLIGHTED,  // 1
    BUTTON_PRESSED,      // 2
    BUTTON_DISABLED,     // 3
    BUTTON_COUNT         // 4 - Must be last.
};

static std::string const data[BUTTON_COUNT] =
{
    "button.xml",
    "button_highlighted.xml",
    "button_pressed.xml",
    "button_disabled.xml"
};

Skin *Button::button[BUTTON_COUNT];

Button::Button(const Widget2 *const widget) :
    gcn::Button(),
    Widget2(widget),
    gcn::WidgetListener(),
    mDescription(""), mClickCount(0),
    mTag(0),
    mVertexes(new GraphicsVertexes()),
    mRedraw(true),
    mMode(0),
    mXOffset(0),
    mYOffset(0),
    mImages(nullptr),
    mImageSet(nullptr),
    mImageWidth(0),
    mImageHeight(0),
    mStick(false),
    mPressed(false)
{
    init();
    adjustSize();
}

Button::Button(const Widget2 *const widget,
               const std::string &caption, const std::string &actionEventId,
               gcn::ActionListener *const listener) :
    gcn::Button(caption),
    Widget2(widget),
    gcn::WidgetListener(),
    mDescription(""),
    mClickCount(0),
    mTag(0),
    mVertexes(new GraphicsVertexes()),
    mRedraw(true),
    mMode(0),
    mXOffset(0),
    mYOffset(0),
    mImages(nullptr),
    mImageSet(nullptr),
    mImageWidth(0),
    mImageHeight(0),
    mStick(false),
    mPressed(false)
{
    init();
    adjustSize();
    setActionEventId(actionEventId);

    if (listener)
        addActionListener(listener);
}

Button::Button(const Widget2 *const widget,
               const std::string &caption, const std::string &imageName,
               const int imageWidth, const int imageHeight,
               const std::string &actionEventId,
               gcn::ActionListener *const listener) :
    gcn::Button(caption),
    Widget2(widget),
    gcn::WidgetListener(),
    mDescription(""),
    mClickCount(0),
    mTag(0),
    mVertexes(new GraphicsVertexes()),
    mRedraw(true),
    mMode(0),
    mXOffset(0),
    mYOffset(0),
    mImages(nullptr),
    mImageSet(nullptr),
    mImageWidth(imageWidth),
    mImageHeight(imageHeight),
    mStick(false),
    mPressed(false)
{
    init();
    loadImage(imageName);
    adjustSize();
    setActionEventId(actionEventId);

    if (listener)
        addActionListener(listener);
}

Button::Button(const Widget2 *const widget, const std::string &imageName,
               const int imageWidth, const int imageHeight,
               const std::string &actionEventId,
               gcn::ActionListener *const listener) :
    gcn::Button(""),
    Widget2(widget),
    gcn::WidgetListener(),
    mDescription(""),
    mClickCount(0),
    mTag(0),
    mVertexes(new GraphicsVertexes()),
    mRedraw(true),
    mMode(0),
    mXOffset(0),
    mYOffset(0),
    mImages(nullptr),
    mImageSet(nullptr),
    mImageWidth(imageWidth),
    mImageHeight(imageHeight),
    mStick(false),
    mPressed(false)
{
    init();
    loadImage(imageName);
    adjustSize();
    setActionEventId(actionEventId);

    if (listener)
        addActionListener(listener);
}

void Button::init()
{
    setFrameSize(0);

    addWidgetListener(this);

    if (mInstances == 0)
    {
        if (Theme::instance())
        {
            for (int mode = 0; mode < BUTTON_COUNT; mode ++)
            {
                button[mode] = Theme::instance()->load(
                    data[mode], "button.xml");
            }
        }

        updateAlpha();
    }
    mEnabledColor = getThemeColor(Theme::BUTTON);
    mDisabledColor = getThemeColor(Theme::BUTTON_DISABLED);
    mHighlightedColor = getThemeColor(Theme::BUTTON_HIGHLIGHTED);
    mPressedColor = getThemeColor(Theme::BUTTON_PRESSED);

    mInstances++;
}

Button::~Button()
{
    mInstances--;

    if (mInstances == 0 && Theme::instance())
    {
        Theme *const theme = Theme::instance();
        for (int mode = 0; mode < BUTTON_COUNT; mode ++)
            theme->unload(button[mode]);
    }
    delete mVertexes;
    mVertexes = nullptr;
    if (mImageSet)
    {
        mImageSet->decRef();
        mImageSet = nullptr;
    }
    if (mImages)
    {
        for (int f = 0; f < BUTTON_COUNT; f ++)
            mImages[f] = nullptr;
        delete [] mImages;
        mImages = nullptr;
    }
}

void Button::loadImage(const std::string &imageName)
{
    if (mImageSet)
    {
        mImageSet->decRef();
        mImageSet = nullptr;
    }
    mImageSet = Theme::getImageSetFromTheme(imageName,
        mImageWidth, mImageHeight);
    if (!mImageSet)
        return;
    mImages = new Image*[BUTTON_COUNT];
    mImages[0] = nullptr;
    for (int f = 0; f < BUTTON_COUNT; f ++)
    {
        Image *const img = mImageSet->get(f);
        if (img)
            mImages[f] = img;
        else
            mImages[f] = mImages[0];
    }
}

void Button::updateAlpha()
{
    const float alpha = std::max(Client::getGuiAlpha(),
        Theme::instance()->getMinimumOpacity());

    if (mAlpha != alpha)
    {
        mAlpha = alpha;
        for (int mode = 0; mode < BUTTON_COUNT; mode ++)
        {
            for (int a = 0; a < 9; a ++)
            {
                Skin *skin = button[mode];
                if (skin)
                {
                    ImageRect &rect = skin->getBorder();
                    Image *image = rect.grid[a];
                    if (image)
                        image->setAlpha(mAlpha);
                }
            }
        }
    }
}

void Button::draw(gcn::Graphics *graphics)
{
    int mode;

    if (!isEnabled())
        mode = BUTTON_DISABLED;
    else if (isPressed2())
        mode = BUTTON_PRESSED;
    else if (mHasMouse || isFocused())
        mode = BUTTON_HIGHLIGHTED;
    else
        mode = BUTTON_STANDARD;

    const Skin *const skin = button[mode];
    if (!skin)
        return;

    updateAlpha();

    Graphics *const g2 = static_cast<Graphics *const>(graphics);

    bool recalc = false;
    if (mRedraw)
    {
        recalc = true;
    }
    else
    {
        // because we don't know where parent windows was moved,
        // need recalc vertexes
        gcn::ClipRectangle &rect = g2->getTopClip();
        if (rect.xOffset != mXOffset || rect.yOffset != mYOffset)
        {
            recalc = true;
            mXOffset = rect.xOffset;
            mYOffset = rect.yOffset;
        }
        else if (mMode != mode)
        {
            recalc = true;
            mMode = mode;
        }
        else if (g2->getRedraw())
        {
            recalc = true;
        }
    }

    if (recalc)
    {
        mRedraw = false;
        mMode = mode;
        g2->calcWindow(mVertexes, 0, 0, getWidth(), getHeight(),
            skin->getBorder());
    }

    g2->drawImageRect2(mVertexes, skin->getBorder());

//    g2->drawImageRect(0, 0, getWidth(), getHeight(), button[mode]);

    const int padding = skin->getPadding();
    const int spacing = skin->getOption("spacing");

    switch (mode)
    {
        case BUTTON_DISABLED:
            graphics->setColor(mDisabledColor);
            break;
        case BUTTON_PRESSED:
            graphics->setColor(mPressedColor);
            break;
        case BUTTON_HIGHLIGHTED:
            graphics->setColor(mHighlightedColor);
            break;
        default:
            graphics->setColor(mEnabledColor);
            break;
    }

    int textX = 0;
    const int textY = getHeight() / 2 - getFont()->getHeight() / 2;
    int imageX = 0;
    int imageY = 0;
    if (mImages)
        imageY = getHeight() / 2 - mImageHeight / 2;

// need move calculation from draw!!!

    switch (getAlignment())
    {
        default:
        case gcn::Graphics::LEFT:
            if (mImages)
            {
                imageX = padding;
                textX = padding + mImageWidth + spacing;
            }
            else
            {
                textX = padding;
            }
            break;
        case gcn::Graphics::CENTER:
            if (mImages)
            {
                const int width = getFont()->getWidth(mCaption)
                    + mImageWidth + spacing;
                imageX = getWidth() / 2 - width / 2;
                textX = imageX + mImageWidth + spacing;
            }
            else
            {
                textX = getWidth() / 2;
            }
            break;
        case gcn::Graphics::RIGHT:
            textX = getWidth() - padding;
            imageX = textX - getFont()->getWidth(mCaption) - spacing;
            break;
    }

    graphics->setFont(getFont());

    if (isPressed())
    {
        if (mImages)
            g2->drawImage(mImages[mode], imageX + 1, imageY + 1);
        g2->drawText(getCaption(), textX + 1, textY + 1, getAlignment());
    }
    else
    {
        if (mImages)
            g2->drawImage(mImages[mode], imageX, imageY);
        g2->drawText(getCaption(), textX, textY, getAlignment());
    }
}

void Button::mouseReleased(gcn::MouseEvent& mouseEvent)
{
    if (mouseEvent.getButton() == gcn::MouseEvent::LEFT)
    {
        if (mStick)
            mPressed = !mPressed;

        if (mMousePressed && mHasMouse)
        {
            mMousePressed = false;
            mClickCount = mouseEvent.getClickCount();
            distributeActionEvent();
        }
        else
        {
            mMousePressed = false;
            mClickCount = 0;
        }
        mouseEvent.consume();
    }
}

void Button::widgetResized(const gcn::Event &event A_UNUSED)
{
    mRedraw = true;
}

void Button::widgetMoved(const gcn::Event &event A_UNUSED)
{
    mRedraw = true;
}

void Button::adjustSize()
{
    const gcn::Font *const font = getFont();
    const Skin *const skin = button[BUTTON_STANDARD];
    if (!skin)
        return;
    const int padding = skin->getPadding();

    if (mImages)
    {
        const int spacing = skin->getOption("spacing");
        const int width = font->getWidth(mCaption);
        if (width)
            setWidth(width + mImageWidth + spacing + 2 * padding);
        else
            setWidth(mImageWidth + 2 * padding);
        int height = font->getHeight();
        if (height < mImageHeight)
            height = mImageHeight;
        setHeight(height + 2 * padding);
    }
    else
    {
        setWidth(font->getWidth(mCaption) + 2 * padding);
        setHeight(font->getHeight() + 2 * padding);
    }
}

void Button::setCaption(const std::string& caption)
{
    mCaption = caption;
}

void Button::keyPressed(gcn::KeyEvent& keyEvent)
{
    const int action = static_cast<KeyEvent*>(&keyEvent)->getActionId();

    if (action == Input::KEY_GUI_SELECT)
    {
        mKeyPressed = true;
        keyEvent.consume();
    }
}

void Button::keyReleased(gcn::KeyEvent& keyEvent)
{
    const int action = static_cast<KeyEvent*>(&keyEvent)->getActionId();

    if (action == Input::KEY_GUI_SELECT && mKeyPressed)
    {
        mKeyPressed = false;
        if (mStick)
            mPressed = !mPressed;
        distributeActionEvent();
        keyEvent.consume();
    }
}


bool Button::isPressed2() const
{
    return (mPressed || isPressed());
}
