/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
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

#ifndef NET_EATHENA_SP_H
#define NET_EATHENA_SP_H

namespace Sp
{
    enum
    {
        SPEED                   = 0,
        BASEEXP                 = 1,
        JOBEXP                  = 2,
        KARMA                   = 3,
        MANNER                  = 4,
        HP                      = 5,
        MAXHP                   = 6,
        SP                      = 7,
        MAXSP                   = 8,
        STATUSPOINT             = 9,
        VAL10                   = 10,
        BASELEVEL               = 11,
        SKILLPOINT              = 12,
        STR                     = 13,
        AGI                     = 14,
        VIT                     = 15,
        INT                     = 16,
        DEX                     = 17,
        LUK                     = 18,
        CLASS                   = 19,
        ZENY                    = 20,
        SEX                     = 21,
        NEXTBASEEXP             = 22,
        NEXTJOBEXP              = 23,
        WEIGHT                  = 24,
        MAXWEIGHT               = 25,
        VAL26                   = 26,
        VAL27                   = 27,
        VAL28                   = 28,
        VAL29                   = 29,
        VAL30                   = 30,
        VAL31                   = 31,
        USTR                    = 32,
        UAGI                    = 33,
        UVIT                    = 34,
        UINT                    = 35,
        UDEX                    = 36,
        ULUK                    = 37,
        VAL38                   = 38,
        VAL39                   = 39,
        VAL40                   = 40,
        ATK1                    = 41,
        ATK2                    = 42,
        MATK1                   = 43,
        MATK2                   = 44,
        DEF1                    = 45,
        DEF2                    = 46,
        MDEF1                   = 47,
        MDEF2                   = 48,
        HIT                     = 49,
        FLEE1                   = 50,
        FLEE2                   = 51,
        CRITICAL                = 52,
        ASPD                    = 53,
        VAL54                   = 54,
        JOBLEVEL                = 55,
        UPPER                   = 56,
        PARTNER                 = 57,
        CART                    = 58,
        FAME                    = 59,
        UNBREAKABLE             = 60,

        CARTINFO                = 99,

        BASEJOB                 = 119,
        BASECLASS               = 120,
        KILLERRID               = 121,
        KILLEDRID               = 122,
        SLOTCHANGE              = 123,
        CHARRENAME              = 124,
        MOD_EXP                 = 125,
        MOD_DROP                = 126,
        MOD_DEATH               = 127,

        MERCFLEE                = 165,

        MERCKILLS               = 189,
        MERCFAITH               = 190,

        ATTACKRANGE             = 1000,
        ATKELE                  = 1001,
        DEFELE                  = 1002,
        CASTRATE                = 1003,
        MAXHPRATE               = 1004,
        MAXSPRATE               = 1005,
        SPRATE                  = 1006,

        ADDELE                  = 1007,
        ADDRACE                 = 1008,
        ADDSIZE                 = 1009,
        SUBELE                  = 1010,
        SUBRACE                 = 1011,
        ADDEFF                  = 1012,
        RESEFF                  = 1013,
        BASE_ATK                = 1014,
        ASPD_RATE               = 1015,
        HP_RECOV_RATE           = 1016,
        RECOV_RATE              = 1017,
        SPEED_RATE              = 1018,
        CRITICAL_DEF            = 1019,
        NEAR_ATK_DEF            = 1020,
        LONG_ATK_DEF            = 1021,
        DOUBLE_RATE             = 1022,
        DOUBLE_ADD_RATE         = 1023,
        SKILL_HEAL              = 1024,
        MATK_RATE               = 1025,
        IGNORE_DEF_ELE          = 1026,
        IGNORE_DEF_RACE         = 1027,
        ATK_RATE                = 1028,
        SPEED_ADDRATE           = 1029,
        REGEN_RATE              = 1030,
        MAGIC_ATK_DEF           = 1031,
        MISC_ATK_DEF            = 1032,
        IGNORE_MDEF_ELE         = 1033,
        IGNORE_MDEF_RACE        = 1034,
        MAGIC_ADDELE            = 1035,
        MAGIC_ADDRACE           = 1036,
        MAGIC_ADDSIZE           = 1037,
        PERFECT_HIT_RATE        = 1038,
        PERFECT_HIT_ADD_RATE    = 1039,
        CRITICAL_RATE           = 1040,
        GET_ZENY_NUM            = 1041,
        ADD_GET_ZENY_NUM        = 1042,
        ADD_DAMAGE_CLASS        = 1043,
        ADD_MAGIC_DAMAGE_CLASS  = 1044,
        ADD_DEF_CLASS           = 1045,
        ADD_MDEF_CLASS          = 1046,
        ADD_MONSTER_DROP_ITEM   = 1047,
        DEF_RATIO_ATK_ELE       = 1048,
        DEF_RATIO_ATK_RACE      = 1049,
        UNBREAKABLE_GARMENT     = 1050,
        HIT_RATE                = 1051,
        FLEE_RATE               = 1052,
        FLEE2_RATE              = 1053,
        DEF_RATE                = 1054,
        DEF2_RATE               = 1055,
        MDEF_RATE               = 1056,
        MDEF2_RATE              = 1057,
        SPLASH_RANGE            = 1058,
        SPLASH_ADD_RANGE        = 1059,
        AUTOSPELL               = 1060,
        HP_DRAIN_RATE           = 1061,
        DRAIN_RATE              = 1062,
        SHORT_WEAPON_DAMAGE_RETURN = 1063,
        LONG_WEAPON_DAMAGE_RETURN = 1064,
        WEAPON_COMA_ELE         = 1065,
        WEAPON_COMA_RACE        = 1066,
        ADDEFF2                 = 1067,
        BREAK_WEAPON_RATE       = 1068,
        BREAK_ARMOR_RATE        = 1069,
        ADD_STEAL_RATE          = 1070,
        MAGIC_DAMAGE_RETURN     = 1071,

        ALL_STATS               = 1073,
        AGI_VIT                 = 1074,
        AGI_DEX_STR             = 1075,
        PERFECT_HIDE            = 1076,
        NO_KNOCKBACK            = 1077,
        CLASSCHANGE             = 1078,
        HP_DRAIN_VALUE          = 1079,
        DRAIN_VALUE             = 1080,
        WEAPON_ATK              = 1081,
        WEAPON_ATK_RATE         = 1082,
        DELAYRATE               = 1083,
        HP_DRAIN_RATE_RACE      = 1084,
        DRAIN_RATE_RACE         = 1085,
        IGNORE_MDEF_RATE        = 1086,
        IGNORE_DEF_RATE         = 1087,
        SKILL_HEAL2             = 1088,
        ADDEFF_ONSKILL          = 1089,
        ADD_HEAL_RATE           = 1090,
        ADD_HEAL2_RATE          = 1091,
        HP_VANISH_RATE          = 1092,

        RESTART_FULL_RECOVER    = 2000,
        NO_CASTCANCEL           = 2001,
        NO_SIZEFIX              = 2002,
        NO_MAGIC_DAMAGE         = 2003,
        NO_WEAPON_DAMAGE        = 2004,
        NO_GEMSTONE             = 2005,
        NO_CASTCANCEL2          = 2006,
        NO_MISC_DAMAGE          = 2007,
        UNBREAKABLE_WEAPON      = 2008,
        UNBREAKABLE_ARMOR       = 2009,
        UNBREAKABLE_HELM        = 2010,
        UNBREAKABLE_SHIELD      = 2011,
        LONG_ATK_RATE           = 2012,

        CRIT_ATK_RATE           = 2013,
        CRITICAL_ADDRACE        = 2014,
        NO_REGEN                = 2015,
        ADDEFF_WHENHIT          = 2016,
        AUTOSPELL_WHENHIT       = 2017,
        SKILL_ATK               = 2018,
        UNSTRIPABLE             = 2019,
        AUTOSPELL_ONSKILL       = 2020,
        GAIN_VALUE              = 2021,
        HP_REGEN_RATE           = 2022,
        HP_LOSS_RATE            = 2023,
        ADDRACE2                = 2024,
        HP_GAIN_VALUE           = 2025,
        SUBSIZE                 = 2026,
        HP_DRAIN_VALUE_RACE     = 2027,
        ADD_ITEM_HEAL_RATE      = 2028,
        DRAIN_VALUE_RACE        = 2029,
        EXP_ADDRACE             = 2030,
        GAIN_RACE               = 2031,
        SUBRACE2                = 2032,
        UNBREAKABLE_SHOES       = 2033,
        UNSTRIPABLE_WEAPON      = 2034,
        UNSTRIPABLE_ARMOR       = 2035,
        UNSTRIPABLE_HELM        = 2036,
        UNSTRIPABLE_SHIELD      = 2037,
        INTRAVISION             = 2038,
        ADD_MONSTER_DROP_CHAINITEM = 2039,
        LOSS_RATE               = 2040,
        ADD_SKILL_BLOW          = 2041,
        VANISH_RATE             = 2042,
        MAGIC_GAIN_VALUE        = 2043,
        MAGIC_HP_GAIN_VALUE     = 2044,
        ADD_CLASS_DROP_ITEM     = 2045,
        EMATK                   = 2046,
        GAIN_RACE_ATTACK        = 2047,
        HP_GAIN_RACE_ATTACK     = 2048,
        SKILL_USE_RATE          = 2049,
        SKILL_COOLDOWN          = 2050,
        SKILL_FIXEDCAST         = 2051,
        SKILL_VARIABLECAST      = 2052,
        FIXCASTRATE             = 2053,
        VARCASTRATE             = 2054,
        SKILL_USE_SP            = 2055,
        MAGIC_ATK_ELE           = 2056,
        ADD_FIXEDCAST           = 2057,
        ADD_VARIABLECAST        = 2058,
        SET_DEF_RACE            = 2059,
        SET_MDEF_RACE           = 2060,
        RACE_TOLERANCE          = 2061,
        ADDMAXWEIGHT            = 2062
    };
}  // namespace Sp

#endif  // NET_EATHENA_SP_H
