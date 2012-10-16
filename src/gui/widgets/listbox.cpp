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

#include "gui/widgets/listbox.h"

#include "client.h"
#include "configuration.h"
#include "keyevent.h"

#include "gui/gui.h"
#include "gui/palette.h"
#include "gui/sdlinput.h"
#include "gui/theme.h"

#include <guichan/focushandler.hpp>
#include <guichan/font.hpp>
#include <guichan/graphics.hpp>
#include <guichan/key.hpp>
#include <guichan/listmodel.hpp>

#include "debug.h"

float ListBox::mAlpha = 1.0;
Skin *ListBox::mSkin = nullptr;
int ListBox::mInstances = 0;

ListBox::ListBox(gcn::ListModel *const listModel):
    gcn::ListBox(listModel),
    mHighlightColor(Theme::getThemeColor(Theme::HIGHLIGHT)),
    mDistributeMousePressed(true),
    mOldSelected(-1),
    mPadding(0)
{
    mForegroundColor = Theme::getThemeColor(Theme::LISTBOX);

    if (mInstances == 0)
    {
        if (Theme::instance())
            mSkin = Theme::instance()->load("listbox.xml", "");
    }
    mInstances ++;

    if (mSkin)
        mPadding = mSkin->getPadding();

    adjustSize();
}

ListBox::~ListBox()
{
    mInstances --;
    if (mInstances == 0 && Theme::instance())
        Theme::instance()->unload(mSkin);
}

void ListBox::updateAlpha()
{
    const float alpha = std::max(Client::getGuiAlpha(),
        Theme::instance()->getMinimumOpacity());

    if (mAlpha != alpha)
        mAlpha = alpha;
}

void ListBox::draw(gcn::Graphics *graphics)
{
    if (!mListModel)
        return;

    updateAlpha();

    mHighlightColor.a = static_cast<int>(mAlpha * 255.0f);
    graphics->setColor(mHighlightColor);
    graphics->setFont(getFont());

    const int height = getRowHeight();

    // Draw filled rectangle around the selected list element
    if (mSelected >= 0)
    {
        graphics->fillRectangle(gcn::Rectangle(mPadding, height * mSelected,
            getWidth() - 2 * mPadding, height));
    }

    // Draw the list elements
    graphics->setColor(mForegroundColor);
    for (int i = 0, y = 0; i < mListModel->getNumberOfElements();
         ++i, y += height)
    {
        graphics->drawText(mListModel->getElementAt(i),
            mPadding, y + mPadding);
    }
}

void ListBox::keyPressed(gcn::KeyEvent &keyEvent)
{
    const int action = static_cast<KeyEvent*>(&keyEvent)->getActionId();

    if (action == Input::KEY_GUI_SELECT)
    {
        distributeActionEvent();
        keyEvent.consume();
    }
    else if (action == Input::KEY_GUI_UP)
    {
        if (getSelected() > 0)
            setSelected(mSelected - 1);
        else if (getSelected() == 0 && mWrappingEnabled && getListModel())
            setSelected(getListModel()->getNumberOfElements() - 1);
        keyEvent.consume();
    }
    else if (action == Input::KEY_GUI_DOWN)
    {
        if (getSelected() < (getListModel()->getNumberOfElements() - 1))
        {
            setSelected(mSelected + 1);
        }
        else if (getSelected() == (getListModel()->getNumberOfElements() - 1)
                 && mWrappingEnabled)
        {
            setSelected(0);
        }
        keyEvent.consume();
    }
    else if (action == Input::KEY_GUI_HOME)
    {
        setSelected(0);
        keyEvent.consume();
    }
    else if (action == Input::KEY_GUI_END && getListModel())
    {
        setSelected(getListModel()->getNumberOfElements() - 1);
        keyEvent.consume();
    }
}

// Don't do anything on scrollwheel. ScrollArea will deal with that.

void ListBox::mouseWheelMovedUp(gcn::MouseEvent &mouseEvent A_UNUSED)
{
}

void ListBox::mouseWheelMovedDown(gcn::MouseEvent &mouseEvent A_UNUSED)
{
}

void ListBox::mousePressed(gcn::MouseEvent &event)
{
    if (mDistributeMousePressed)
    {
        mousePressed1(event);
    }
    else
    {
        switch (event.getClickCount())
        {
            case 1:
                mouseDragged(event);
                mOldSelected = mSelected;
                break;
            case 2:
                if (gui)
                    gui->resetClickCount();
                if (mOldSelected == mSelected)
                    mousePressed1(event);
                else
                    mouseDragged(event);
                mOldSelected = mSelected;
                break;
            default:
                mouseDragged(event);
                mOldSelected = mSelected;
                break;
        }
    }
}

void ListBox::mousePressed1(gcn::MouseEvent &mouseEvent)
{
    if (mouseEvent.getButton() == gcn::MouseEvent::LEFT)
    {
        setSelected(std::max(0, mouseEvent.getY() - mPadding)
            / getRowHeight());
        distributeActionEvent();
    }
}

void ListBox::mouseDragged(gcn::MouseEvent &event)
{
    if (event.getButton() != gcn::MouseEvent::LEFT || getRowHeight() == 0)
        return;

    // Make list selection update on drag, but guard against negative y
    if (getRowHeight())
        setSelected(std::max(0, event.getY() - mPadding) / getRowHeight());
}

void ListBox::refocus()
{
    if (!mFocusHandler)
        return;

    if (isFocusable())
        mFocusHandler->requestFocus(this);
}

void ListBox::adjustSize()
{
    if (mListModel)
    {
        setHeight(getRowHeight() * mListModel->getNumberOfElements()
            + 2 * mPadding);
    }
}

void ListBox::logic()
{
    adjustSize();
}
