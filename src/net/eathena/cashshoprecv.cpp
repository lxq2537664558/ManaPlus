/*
 *  The ManaPlus Client
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

#include "net/eathena/cashshoprecv.h"

#include "being/playerinfo.h"

#include "gui/windows/buydialog.h"

#include "gui/widgets/createwidget.h"

#include "net/eathena/messageout.h"
#include "net/eathena/protocol.h"

#include "debug.h"

namespace EAthena
{

namespace CashShopRecv
{
    BuyDialog *mBuyDialog;
}

void CashShopRecv::processCashShopOpen(Net::MessageIn &msg)
{
    const int count = (msg.readInt16("len") - 12) / 11;

    CREATEWIDGETV(mBuyDialog, BuyDialog, fromInt(BuyDialog::Cash, BeingId));
    mBuyDialog->setMoney(PlayerInfo::getAttribute(Attributes::MONEY));

    msg.readInt32("cash points");
    msg.readInt32("kafra points");
    for (int f = 0; f < count; f ++)
    {
        msg.readInt32("price");
        const int value = msg.readInt32("discount price");
        const int type = msg.readUInt8("item type");
        const int itemId = msg.readInt16("item id");
        const ItemColor color = ItemColor_one;
        mBuyDialog->addItem(itemId, type, color, 0, value);
    }
    mBuyDialog->sort();
}

void CashShopRecv::processCashShopBuyAck(Net::MessageIn &msg)
{
    UNIMPLIMENTEDPACKET;
    msg.readInt32("cash points");
    msg.readInt32("kafra points");
    msg.readInt16("error");
}

void CashShopRecv::processCashShopPoints(Net::MessageIn &msg)
{
    UNIMPLIMENTEDPACKET;
    msg.readInt32("cash points");
    msg.readInt32("kafra points");
}

void CashShopRecv::processCashShopBuy(Net::MessageIn &msg)
{
    UNIMPLIMENTEDPACKET;
    msg.readInt32("id");
    msg.readInt16("result");
    msg.readInt32("cash points");
    msg.readInt32("kafra points");
}

void CashShopRecv::processCashShopTabPriceList(Net::MessageIn &msg)
{
    UNIMPLIMENTEDPACKET;
    const int count = (msg.readInt16("len") - 10) / 6;
    msg.readInt32("tab");
    const int itemsCount = msg.readInt16("count");
    if (count != itemsCount)
        logger->log("error: wrong list count");

    for (int f = 0; f < count; f ++)
    {
        msg.readInt16("item id");
        msg.readInt32("price");
    }
}

void CashShopRecv::processCashShopSchedule(Net::MessageIn &msg)
{
    UNIMPLIMENTEDPACKET;
    const int count = (msg.readInt16("len") - 8) / 6;
    const int itemsCount = msg.readInt16("count");
    msg.readInt16("tab");
    if (count != itemsCount)
        logger->log("error: wrong list count");

    for (int f = 0; f < count; f ++)
    {
        msg.readInt16("item id");
        msg.readInt32("price");
    }
}

}  // namespace EAthena