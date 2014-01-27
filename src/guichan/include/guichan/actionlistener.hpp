/*      _______   __   __   __   ______   __   __   _______   __   __
 *     / _____/\ / /\ / /\ / /\ / ____/\ / /\ / /\ / ___  /\ /  |\/ /\
 *    / /\____\// / // / // / // /\___\// /_// / // /\_/ / // , |/ / /
 *   / / /__   / / // / // / // / /    / ___  / // ___  / // /| ' / /
 *  / /_// /\ / /_// / // / // /_/_   / / // / // /\_/ / // / |  / /
 * /______/ //______/ //_/ //_____/\ /_/ //_/ //_/ //_/ //_/ /|_/ /
 * \______\/ \______\/ \_\/ \_____\/ \_\/ \_\/ \_\/ \_\/ \_\/ \_\/
 *
 * Copyright (c) 2004 - 2008 Olof Naess�n and Per Larsson
 * Copyright (C) 2011-2014  The ManaPlus Developers
 *
 *
 * Per Larsson a.k.a finalman
 * Olof Naess�n a.k.a jansem/yakslem
 *
 * Visit: http://guichan.sourceforge.net
 *
 * License: (BSD)
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Guichan nor the names of its contributors may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GCN_ACTIONLISTENER_HPP
#define GCN_ACTIONLISTENER_HPP

#include <string>

#include "guichan/actionevent.hpp"

namespace gcn
{
    /**
     * Interface for listening for action events from widgets.
     *
     * @see Widget::addActionListener, Widget::removeActionListener,
     *      ActionEvent
     * @author Olof Naess�n
     * @author Per Larsson
     */
    class ActionListener
    {
    public:
        /**
         * Destructor.
         */
        virtual ~ActionListener()
        { }

        /**
         * Called when an action is recieved from a widget. It is used
         * to be able to recieve a notification that an action has
         * occured.
         *
         * @param actionEvent The event of the action.
         * @since 0.6.0
         */
        virtual void action(const ActionEvent& actionEvent) = 0;

    protected:
        /**
         * Constructor.
         *
         * You should not be able to make an instance of ActionListener,
         * therefore its constructor is protected.
         */
        ActionListener()
        { }
    };
}  // namespace gcn

#endif  // end GCN_ACTIONLISTENER_HPP
