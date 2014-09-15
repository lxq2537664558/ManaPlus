/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
 *  Copyright (C) 2011-2014  The ManaPlus Developers
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

#ifndef NET_EATHENA_ADMINHANDLER_H
#define NET_EATHENA_ADMINHANDLER_H

#include "net/ea/adminhandler.h"

#include "net/eathena/messagehandler.h"

namespace EAthena
{

class AdminHandler final : public MessageHandler, public Ea::AdminHandler
{
    public:
        AdminHandler();

        A_DELETE_COPY(AdminHandler)

        void handleMessage(Net::MessageIn &msg) override final;

        void announce(const std::string &text) const override final;

        void localAnnounce(const std::string &text) const override final;

        void hide(const bool h) const override final;

        void kick(const int playerId) const override final;

        void kickAll() const override final;

        void warp(const std::string &map,
                  const int x, const int y) const override final;

        void resetStats() const override final;

        void resetSkills() const override final;

        void gotoName(const std::string &name) const override final;

        void recallName(const std::string &name) const override final;

        void mute(const Being *const being,
                  const int type,
                  const int limit) const override final;

        void muteName(const std::string &name) const override final;

        void requestLogin(const Being *const being) const override final;

        void setTileType(const int x, const int y,
                         const int type) const;

        void unequipAll(const Being *const being) const override final;

        void requestStats(const std::string &name) override final;

    protected:
        void processAdminGetLoginAck(Net::MessageIn &msg);

        void processSetTileType(Net::MessageIn &msg);

        void processAccountStats(Net::MessageIn &msg);

        std::string mStatsName;
};

}  // namespace EAthena

#endif  // NET_EATHENA_ADMINHANDLER_H
