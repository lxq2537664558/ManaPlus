/*
 *  The ManaPlus Client
 *  Copyright (C) 2007  Joshua Langley <joshlangley@optusnet.com.au>
 *  Copyright (C) 2009-2010  The Mana Developers
 *  Copyright (C) 2011-2016  The ManaPlus Developers
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

#ifndef ENUMS_INPUT_INPUTACTION_H
#define ENUMS_INPUT_INPUTACTION_H

#include "enums/simpletypes/enumdefines.h"

#ifdef WIN32
#undef ERROR
#undef IGNORE
#endif

/**
  * All the key functions.
  * KEY_NO_VALUE is used in initialization, and should be unchanged.
  * KEY_TOTAL should always be last (used as a conditional in loops).
  * The key assignment view gets arranged according to the order of
  * these values.
  */
enumStart(InputAction)
{
    UNDEFINED_VALUE = -2,
    NO_VALUE = -1,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    ATTACK,
    TARGET_ATTACK,
    MOVE_TO_TARGET,
    CHANGE_MOVE_TO_TARGET,
    MOVE_TO_HOME,
    SET_HOME,
    MOVE_TO_POINT,
    TALK,
    STOP_ATTACK,
    UNTARGET,
    TARGET_MONSTER,
    TARGET_NPC,
    TARGET_PLAYER,
    PICKUP,
    CHANGE_PICKUP_TYPE,
    HIDE_WINDOWS,
    SIT,
    SCREENSHOT,
    CHANGE_TRADE,
    PATHFIND,
    OK,
    QUIT,
    SHORTCUTS_KEY,
    SHORTCUT_1,
    SHORTCUT_2,
    SHORTCUT_3,
    SHORTCUT_4,
    SHORTCUT_5,
    SHORTCUT_6,
    SHORTCUT_7,
    SHORTCUT_8,
    SHORTCUT_9,
    SHORTCUT_10,
    SHORTCUT_11,
    SHORTCUT_12,
    SHORTCUT_13,
    SHORTCUT_14,
    SHORTCUT_15,
    SHORTCUT_16,
    SHORTCUT_17,
    SHORTCUT_18,
    SHORTCUT_19,
    SHORTCUT_20,
    WINDOW_HELP,
    WINDOW_STATUS,
    WINDOW_INVENTORY,
    WINDOW_EQUIPMENT,
    WINDOW_SKILL,
    WINDOW_MINIMAP,
    WINDOW_CHAT,
    WINDOW_SHORTCUT,
    WINDOW_SETUP,
    WINDOW_DEBUG,
    WINDOW_SOCIAL,
    WINDOW_EMOTE_SHORTCUT,
    WINDOW_OUTFIT,
    WINDOW_SHOP,
    WINDOW_DROP,
    WINDOW_KILLS,
    WINDOW_SPELLS,
    UNUSED1,
    WINDOW_ONLINE,
    WINDOW_DIDYOUKNOW,
    WINDOW_QUESTS,
    PREV_SOCIAL_TAB,
    NEXT_SOCIAL_TAB,
    EMOTE,
    EMOTE_1,
    EMOTE_2,
    EMOTE_3,
    EMOTE_4,
    EMOTE_5,
    EMOTE_6,
    EMOTE_7,
    EMOTE_8,
    EMOTE_9,
    EMOTE_10,
    EMOTE_11,
    EMOTE_12,
    EMOTE_13,
    EMOTE_14,
    EMOTE_15,
    EMOTE_16,
    EMOTE_17,
    EMOTE_18,
    EMOTE_19,
    EMOTE_20,
    EMOTE_21,
    EMOTE_22,
    EMOTE_23,
    EMOTE_24,
    EMOTE_25,
    EMOTE_26,
    EMOTE_27,
    EMOTE_28,
    EMOTE_29,
    EMOTE_30,
    EMOTE_31,
    EMOTE_32,
    EMOTE_33,
    EMOTE_34,
    EMOTE_35,
    EMOTE_36,
    EMOTE_37,
    EMOTE_38,
    EMOTE_39,
    EMOTE_40,
    EMOTE_41,
    EMOTE_42,
    EMOTE_43,
    EMOTE_44,
    EMOTE_45,
    EMOTE_46,
    EMOTE_47,
    EMOTE_48,
    WEAR_OUTFIT,
    COPY_OUTFIT,
    COPY_EQUIPED_OUTFIT,
    OUTFIT_1,
    OUTFIT_2,
    OUTFIT_3,
    OUTFIT_4,
    OUTFIT_5,
    OUTFIT_6,
    OUTFIT_7,
    OUTFIT_8,
    OUTFIT_9,
    OUTFIT_10,
    OUTFIT_11,
    OUTFIT_12,
    OUTFIT_13,
    OUTFIT_14,
    OUTFIT_15,
    OUTFIT_16,
    OUTFIT_17,
    OUTFIT_18,
    OUTFIT_19,
    OUTFIT_20,
    OUTFIT_21,
    OUTFIT_22,
    OUTFIT_23,
    OUTFIT_24,
    OUTFIT_25,
    OUTFIT_26,
    OUTFIT_27,
    OUTFIT_28,
    OUTFIT_29,
    OUTFIT_30,
    OUTFIT_31,
    OUTFIT_32,
    OUTFIT_33,
    OUTFIT_34,
    OUTFIT_35,
    OUTFIT_36,
    OUTFIT_37,
    OUTFIT_38,
    OUTFIT_39,
    OUTFIT_40,
    OUTFIT_41,
    OUTFIT_42,
    OUTFIT_43,
    OUTFIT_44,
    OUTFIT_45,
    OUTFIT_46,
    OUTFIT_47,
    OUTFIT_48,
    MOVE_TO_POINT_1,
    MOVE_TO_POINT_2,
    MOVE_TO_POINT_3,
    MOVE_TO_POINT_4,
    MOVE_TO_POINT_5,
    MOVE_TO_POINT_6,
    MOVE_TO_POINT_7,
    MOVE_TO_POINT_8,
    MOVE_TO_POINT_9,
    MOVE_TO_POINT_10,
    MOVE_TO_POINT_11,
    MOVE_TO_POINT_12,
    MOVE_TO_POINT_13,
    MOVE_TO_POINT_14,
    MOVE_TO_POINT_15,
    MOVE_TO_POINT_16,
    MOVE_TO_POINT_17,
    MOVE_TO_POINT_18,
    MOVE_TO_POINT_19,
    MOVE_TO_POINT_20,
    MOVE_TO_POINT_21,
    MOVE_TO_POINT_22,
    MOVE_TO_POINT_23,
    MOVE_TO_POINT_24,
    MOVE_TO_POINT_25,
    MOVE_TO_POINT_26,
    MOVE_TO_POINT_27,
    MOVE_TO_POINT_28,
    MOVE_TO_POINT_29,
    MOVE_TO_POINT_30,
    MOVE_TO_POINT_31,
    MOVE_TO_POINT_32,
    MOVE_TO_POINT_33,
    MOVE_TO_POINT_34,
    MOVE_TO_POINT_35,
    MOVE_TO_POINT_36,
    MOVE_TO_POINT_37,
    MOVE_TO_POINT_38,
    MOVE_TO_POINT_39,
    MOVE_TO_POINT_40,
    MOVE_TO_POINT_41,
    MOVE_TO_POINT_42,
    MOVE_TO_POINT_43,
    MOVE_TO_POINT_44,
    MOVE_TO_POINT_45,
    MOVE_TO_POINT_46,
    MOVE_TO_POINT_47,
    MOVE_TO_POINT_48,
    TOGGLE_CHAT,
    SCROLL_CHAT_UP,
    SCROLL_CHAT_DOWN,
    PREV_CHAT_TAB,
    NEXT_CHAT_TAB,
    CLOSE_CHAT_TAB,
    CHAT_PREV_HISTORY,
    CHAT_NEXT_HISTORY,
    IGNORE_INPUT_1,
    IGNORE_INPUT_2,
    DIRECT_UP,
    DIRECT_DOWN,
    DIRECT_LEFT,
    DIRECT_RIGHT,
    CRAZY_MOVES,
    CHANGE_CRAZY_MOVES_TYPE,
    QUICK_DROP,
    QUICK_DROPN,
    SWITCH_QUICK_DROP,
    MAGIC_INMA1,
    MAGIC_ITENPLZ,
    MAGIC_ATTACK,
    SWITCH_MAGIC_ATTACK,
    SWITCH_PVP_ATTACK,
    INVERT_DIRECTION,
    CHANGE_ATTACK_WEAPON_TYPE,
    CHANGE_ATTACK_TYPE,
    CHANGE_FOLLOW_MODE,
    CHANGE_IMITATION_MODE,
    DISABLE_GAME_MODIFIERS,
    CHANGE_AUDIO,
    AWAY,
    RIGHT_CLICK,
    CAMERA,
    RESERVED1,
    GUI_UP,
    GUI_DOWN,
    GUI_LEFT,
    GUI_RIGHT,
    GUI_SELECT,
    GUI_SELECT2,
    GUI_CANCEL,
    GUI_HOME,
    GUI_END,
    GUI_DELETE,
    GUI_BACKSPACE,
    GUI_TAB,
    GUI_PAGE_UP,
    GUI_PAGE_DOWN,
    GUI_INSERT,
    GUI_MOD,
    SAFE_VIDEO,
    STOP_SIT,
    SHOW_KEYBOARD,
    SHOW_WINDOWS,
    CHAT_MOD,
    MOVE_FORWARD,
    GUI_CTRL,
    GUI_B,
    GUI_C,
    GUI_D,
    GUI_E,
    GUI_F,
    GUI_H,
    GUI_K,
    GUI_U,
    GUI_V,
    GUI_W,
    PREV_SHORTCUTS_TAB,
    NEXT_SHORTCUTS_TAB,
    PREV_COMMANDS_TAB,
    NEXT_COMMANDS_TAB,
    OPEN_TRADE,
    GUI_F1,
    GUI_F2,
    GUI_F3,
    GUI_F4,
    GUI_F5,
    GUI_F6,
    GUI_F7,
    GUI_F8,
    GUI_F9,
    GUI_F10,
    GUI_F11,
    GUI_F12,
    WINDOW_ABOUT,
    WINDOW_UPDATER,
    TARGET_CLOSEST_MONSTER,
    CLOSE_ALL_CHAT_TABS,
    IGNORE_ALL_WHISPERS,
    CHAT_ANNOUNCE,
    IPC_TOGGLE,
    WHERE,
    WHO,
    WHISPER,
    QUERY,
    CLEAR_CHAT_TAB,
    IGNORE,
    UNIGNORE,
    FRIEND,
    DISREGARD,
    NEUTRAL,
    BLACKLIST,
    ENEMY,
    ERASE,
    CLEAN_GRAPHICS,
    CLEAN_FONTS,
    CREATE_PARTY,
    CREATE_GUILD,
    PARTY,
    ME,
    TOGGLE,
    PRESENT,
    PRINT_ALL,
    MOVE,
    TARGET,
    ATTACK_HUMAN,
    COMMAMD_OUTFIT,
    COMMAMD_EMOTE,
    COMMAND_EMOTE_PET,
    AWAY_MESSAGE,
    PSEUDO_AWAY,
    FOLLOW,
    NAVIGATE,
    IMITATION,
    SEND_MAIL,
    TRADE,
    PRICE_LOAD,
    PRICE_SAVE,
    CACHE_INFO,
    DISCONNECT,
    UNDRESS,
    DIRS,
    INFO,
    WAIT,
    UPTIME,
    ADD_PRIORITY_ATTACK,
    ADD_ATTACK,
    REMOVE_ATTACK,
    ADD_IGNORE_ATTACK,
    DUMP,
    SERVER_IGNORE_ALL,
    SERVER_UNIGNORE_ALL,
    SET_DROP,
    ERROR,
    DUMP_GRAPHICS,
    DUMP_ENVIRONMENT,
    DUMP_TESTS,
    DUMP_OGL,
    DUMP_GL,
    DUMP_MODS,
    URL,
    OPEN_URL,
    EXECUTE,
    TEST_SDL_FONT,
    ENABLE_HIGHLIGHT,
    DISABLE_HIGHLIGHT,
    DONT_REMOVE_NAME,
    REMOVE_NAME,
    DISABLE_AWAY,
    ENABLE_AWAY,
    TEST_PARTICLE,
    CREATE_ITEMS,
    TALK_RAW,
    TALK_PET,
    UPLOAD_CONFIG,
    UPLOAD_SERVER_CONFIG,
    UPLOAD_LOG,
    GM,
    HACK,
    DEBUG_SPAWN,
    PET_EMOTE,
    PET_EMOTE_1,
    PET_EMOTE_2,
    PET_EMOTE_3,
    PET_EMOTE_4,
    PET_EMOTE_5,
    PET_EMOTE_6,
    PET_EMOTE_7,
    PET_EMOTE_8,
    PET_EMOTE_9,
    PET_EMOTE_10,
    PET_EMOTE_11,
    PET_EMOTE_12,
    PET_EMOTE_13,
    PET_EMOTE_14,
    PET_EMOTE_15,
    PET_EMOTE_16,
    PET_EMOTE_17,
    PET_EMOTE_18,
    PET_EMOTE_19,
    PET_EMOTE_20,
    PET_EMOTE_21,
    PET_EMOTE_22,
    PET_EMOTE_23,
    PET_EMOTE_24,
    PET_EMOTE_25,
    PET_EMOTE_26,
    PET_EMOTE_27,
    PET_EMOTE_28,
    PET_EMOTE_29,
    PET_EMOTE_30,
    PET_EMOTE_31,
    PET_EMOTE_32,
    PET_EMOTE_33,
    PET_EMOTE_34,
    PET_EMOTE_35,
    PET_EMOTE_36,
    PET_EMOTE_37,
    PET_EMOTE_38,
    PET_EMOTE_39,
    PET_EMOTE_40,
    PET_EMOTE_41,
    PET_EMOTE_42,
    PET_EMOTE_43,
    PET_EMOTE_44,
    PET_EMOTE_45,
    PET_EMOTE_46,
    PET_EMOTE_47,
    PET_EMOTE_48,
    CATCH_PET,
    IGNORE_WHISPER,
    UNIGNORE_WHISPER,
    MERCENARY_FIRE,
    TARGET_MERCENARY,
    TARGET_PET,
    PET_SET_NAME,
    HOMUNCULUS_SET_NAME,
    HOMUNCULUS_FIRE,
    WINDOW_BANK,
    PREV_INV_TAB,
    NEXT_INV_TAB,
    CONTEXT_MENU,
    BUY,
    SELL,
    WHISPER2,
    GUILD,
    NUKE,
    USE,
    CHAT_ADD,
    WHISPER_TEXT,
    NAVIGATE_TO,
    CAMERA_MOVE,
    DROP_ITEM,
    DROP_ITEM_ALL,
    DROP_INV,
    DROP_INV_ALL,
    USE_INV,
    INV_TO_STORAGE,
    TRADE_ADD,
    STORAGE_TO_INV,
    ITEM_PROTECT,
    ITEM_UNPROTECT,
    KICK_PARTY,
    ADD_TEXT,
    KICK,
    LEAVE_PARTY,
    WARP,
    CLEAR_CHAT,
    PET_MOVE_UP,
    PET_MOVE_DOWN,
    PET_MOVE_LEFT,
    PET_MOVE_RIGHT,
    PET_DIRECT_UP,
    PET_DIRECT_DOWN,
    PET_DIRECT_LEFT,
    PET_DIRECT_RIGHT,
    PET_AI_START,
    PET_AI_STOP,
    CHAT_GENERAL_TAB,
    CHAT_DEBUG_TAB,
    CHAT_BATTLE_TAB,
    CHAT_TRADE_TAB,
    CHAT_LANG_TAB,
    CHAT_GM_TAB,
    CHAT_PARTY_TAB,
    CHAT_GUILD_TAB,
    DROP_CLEAR,
    WINDOW_CART,
    HEAL_MOST_DAMAGED,
    PET_MOVE,
    HOMUN_TALK,
    HOMUN_SMILE,
    HOMUN_EMOTE,
    HOMUN_EMOTE_1,
    HOMUN_EMOTE_2,
    HOMUN_EMOTE_3,
    HOMUN_EMOTE_4,
    HOMUN_EMOTE_5,
    HOMUN_EMOTE_6,
    HOMUN_EMOTE_7,
    HOMUN_EMOTE_8,
    HOMUN_EMOTE_9,
    HOMUN_EMOTE_10,
    HOMUN_EMOTE_11,
    HOMUN_EMOTE_12,
    HOMUN_EMOTE_13,
    HOMUN_EMOTE_14,
    HOMUN_EMOTE_15,
    HOMUN_EMOTE_16,
    HOMUN_EMOTE_17,
    HOMUN_EMOTE_18,
    HOMUN_EMOTE_19,
    HOMUN_EMOTE_20,
    HOMUN_EMOTE_21,
    HOMUN_EMOTE_22,
    HOMUN_EMOTE_23,
    HOMUN_EMOTE_24,
    HOMUN_EMOTE_25,
    HOMUN_EMOTE_26,
    HOMUN_EMOTE_27,
    HOMUN_EMOTE_28,
    HOMUN_EMOTE_29,
    HOMUN_EMOTE_30,
    HOMUN_EMOTE_31,
    HOMUN_EMOTE_32,
    HOMUN_EMOTE_33,
    HOMUN_EMOTE_34,
    HOMUN_EMOTE_35,
    HOMUN_EMOTE_36,
    HOMUN_EMOTE_37,
    HOMUN_EMOTE_38,
    HOMUN_EMOTE_39,
    HOMUN_EMOTE_40,
    HOMUN_EMOTE_41,
    HOMUN_EMOTE_42,
    HOMUN_EMOTE_43,
    HOMUN_EMOTE_44,
    HOMUN_EMOTE_45,
    HOMUN_EMOTE_46,
    HOMUN_EMOTE_47,
    HOMUN_EMOTE_48,
    KICK_GUILD,
    HAT,
    CREATE_PUBLIC_ROOM,
    JOIN_ROOM,
    LEAVE_ROOM,
    WINDOW_QUICK_SETTINGS,
    WINDOW_MAIL,
    CONF_SET,
    SERVER_CONF_SET,
    CONG_GET,
    SERVER_CONG_GET,
    CHANGE_TARGETING_TYPE,
    TEST_INFO,
    SLIDE,
    SELECT_SKILL_LEVEL,
    SKILL,
    CRAFT_1,
    CRAFT_2,
    CRAFT_3,
    CRAFT_4,
    CRAFT_5,
    CRAFT_6,
    CRAFT_7,
    CRAFT_8,
    CRAFT_9,
    CRAFT,
    CHAT_CLIPBOARD,
    NPC_CLIPBOARD,
    ADD_PICKUP,
    REMOVE_PICKUP,
    IGNORE_PICKUP,
    RESET_MODIFIERS,
    BAR_TO_CHAT,
    SEEN,
    TARGET_SKILL_UNIT,
    MONSTER_INFO,
    ITEM_INFO,
    WHO_DROPS,
    MOB_SEARCH,
    MOB_SPAWN_SEARCH,
    PLAYER_GM_COMMANDS,
    PLAYER_CHAR_GM_COMMANDS,
    COMMAND_SHOW_LEVEL,
    COMMAND_SHOW_STATS,
    COMMAND_SHOW_STORAGE,
    COMMAND_SHOW_CART,
    COMMAND_SHOW_INVENTORY,
    LOCATE_PLAYER,
    COMMAND_SHOW_ACCOUNT_INFO,
    COMMAND_SPAWN,
    COMMAND_SPAWN_SLAVE,
    COMMAND_SPAWN_CLONE,
    COMMAND_SPAWN_SLAVE_CLONE,
    COMMAND_SPAWN_EVIL_CLONE,
    COMMAND_SAVE_POSITION,
    COMMAND_LOAD_POSITION,
    COMMAND_RANDOM_WARP,
    COMMAND_GOTO_NPC,
    COMMAND_KILLER,
    COMMAND_KILLABLE,
    TOTAL
}
enumEnd(InputAction);

#endif  // ENUMS_INPUT_INPUTACTION_H
