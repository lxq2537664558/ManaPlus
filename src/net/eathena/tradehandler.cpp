/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
 *  Copyright (C) 2011-2015  The ManaPlus Developers
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

#include "net/eathena/tradehandler.h"

#include "inventory.h"
#include "item.h"
#include "itemcolormanager.h"
#include "notifymanager.h"

#include "being/playerinfo.h"

#include "enums/resources/notifytypes.h"

#include "gui/windows/tradewindow.h"

#include "net/ea/traderecv.h"

#include "net/eathena/messageout.h"
#include "net/eathena/protocol.h"
#include "net/eathena/traderecv.h"

#include "net/ea/eaprotocol.h"

#include "debug.h"

extern Net::TradeHandler *tradeHandler;

namespace EAthena
{
TradeHandler::TradeHandler() :
    MessageHandler(),
    Ea::TradeHandler()
{
    static const uint16_t _messages[] =
    {
        SMSG_TRADE_REQUEST,
        SMSG_TRADE_RESPONSE,
        SMSG_TRADE_ITEM_ADD,
        SMSG_TRADE_ITEM_ADD_RESPONSE,
        SMSG_TRADE_OK,
        SMSG_TRADE_CANCEL,
        SMSG_TRADE_COMPLETE,
        SMSG_TRADE_UNDO,
        0
    };
    handledMessages = _messages;
    tradeHandler = this;
    TradeRecv::mItemIndex = -1;
    TradeRecv::mQuantity = 0;
}


void TradeHandler::handleMessage(Net::MessageIn &msg)
{
    switch (msg.getId())
    {
        case SMSG_TRADE_REQUEST:
            TradeRecv::processTradeRequest(msg);
            break;

        case SMSG_TRADE_RESPONSE:
            TradeRecv::processTradeResponse(msg);
            break;

        case SMSG_TRADE_ITEM_ADD:
            TradeRecv::processTradeItemAdd(msg);
            break;

        case SMSG_TRADE_ITEM_ADD_RESPONSE:
            TradeRecv::processTradeItemAddResponse(msg);
            break;

        case SMSG_TRADE_OK:
            Ea::TradeRecv::processTradeOk(msg);
            break;

        case SMSG_TRADE_CANCEL:
            Ea::TradeRecv::processTradeCancel(msg);
            break;

        case SMSG_TRADE_COMPLETE:
            Ea::TradeRecv::processTradeComplete(msg);
            break;

        case SMSG_TRADE_UNDO:
            TradeRecv::processTradeUndo(msg);
            break;

        default:
            break;
    }
}

void TradeHandler::request(const Being *const being) const
{
    if (!being)
        return;

    createOutPacket(CMSG_TRADE_REQUEST);
    outMsg.writeBeingId(being->getId(), "player id");
}

void TradeHandler::respond(const bool accept) const
{
    if (!accept)
        PlayerInfo::setTrading(Trading_false);

    createOutPacket(CMSG_TRADE_RESPONSE);
    outMsg.writeInt8(static_cast<int8_t>(accept ? 3 : 4), "accept");
}

void TradeHandler::addItem(const Item *const item, const int amount) const
{
    if (!item)
        return;

    TradeRecv::mItemIndex = item->getInvIndex();
    TradeRecv::mQuantity = amount;
    createOutPacket(CMSG_TRADE_ITEM_ADD_REQUEST);
    outMsg.writeInt16(static_cast<int16_t>(
        TradeRecv::mItemIndex + INVENTORY_OFFSET),
        "index");
    outMsg.writeInt32(amount, "amount");
}

void TradeHandler::setMoney(const int amount) const
{
    createOutPacket(CMSG_TRADE_ITEM_ADD_REQUEST);
    outMsg.writeInt16(0, "index");
    outMsg.writeInt32(amount, "amount");
}

void TradeHandler::confirm() const
{
    createOutPacket(CMSG_TRADE_ADD_COMPLETE);
}

void TradeHandler::finish() const
{
    createOutPacket(CMSG_TRADE_OK);
}

void TradeHandler::cancel() const
{
    createOutPacket(CMSG_TRADE_CANCEL_REQUEST);
}

}  // namespace EAthena
