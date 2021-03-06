#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

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