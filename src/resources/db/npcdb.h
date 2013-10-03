/*
 *  The ManaPlus Client
 *  Copyright (C) 2008-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
 *  Copyright (C) 2011-2013  The ManaPlus Developers
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

#ifndef RESOURCES_DB_NPCDB_H
#define RESOURCES_DB_NPCDB_H

#include <stdint.h>

#include <string>

#include "localconsts.h"

class BeingInfo;

/**
 * NPC information database.
 */
namespace NPCDB
{
    void load();

    void unload();

    BeingInfo *get(const int id) A_WARN_UNUSED;

    uint16_t getAvatarFor(const int id);

    void loadXmlFile(const std::string &fileName);
}  // namespace NPCDB

#endif  // RESOURCES_DB_NPCDB_H
