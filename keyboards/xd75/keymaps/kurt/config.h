/* Copyright 2019 Kurt Lachmann
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Use constant cursor speed
#define MK_3_SPEED

// Enable momentary cursor speed selection (i.e. hold down speed keys)
#define MK_MOMENTARY_ACCEL

// Default cursor speed
#define MK_C_OFFSET_UNMOD 8 // Cursor offset per movement
#define MK_C_INTERVAL_UNMOD 16 // Time between cursor movements in ms

// KC_ACL0
#define MK_C_OFFSET_0 1
#define MK_C_INTERVAL_0 16

// KC_ACL1
#define MK_C_OFFSET_1 3
#define MK_C_INTERVAL_1 16

// KC_ACL2
#define MK_C_OFFSET_2 32
#define MK_C_INTERVAL_2 16
