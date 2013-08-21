/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
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

#include "resources/sdlmusic.h"

#include "logger.h"

#include "debug.h"

SDLMusic::SDLMusic(Mix_Music *const music) :
    Resource(),
    mMusic(music)
{
}

SDLMusic::~SDLMusic()
{
    Mix_FreeMusic(mMusic);
}

Resource *SDLMusic::load(SDL_RWops *const rw)
{
#ifdef USE_SDL2
    if (Mix_Music *const music = Mix_LoadMUS_RW(rw, 1))
#else
    if (Mix_Music *const music = Mix_LoadMUS_RW(rw))
#endif
    {
        return new SDLMusic(music);
    }
    else
    {
        logger->log("Error, failed to load music: %s", Mix_GetError());
        return nullptr;
    }
}

bool SDLMusic::play(const int loops, const int fadeIn)
{
    if (fadeIn > 0)
        return Mix_FadeInMusic(mMusic, loops, fadeIn);
    else
        return Mix_PlayMusic(mMusic, loops);
}
