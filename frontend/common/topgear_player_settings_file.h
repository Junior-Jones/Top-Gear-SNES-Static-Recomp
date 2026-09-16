#ifndef TOPGEAR_PLAYER_SETTINGS_FILE_H
#define TOPGEAR_PLAYER_SETTINGS_FILE_H
#include "topgear_static_recomp.h"
/* UTF-8 paths. Cache changes only after durable replacement. Missing file
   means defaults; malformed existing files fail without overwrite. */
int topgear_player_settings_load_file(TopGearRecomp*,const char*,uint8_t cache[TOPGEAR_PLAYER_SETTINGS_SIZE]);
int topgear_player_settings_save_file(TopGearRecomp*,const char*,uint8_t cache[TOPGEAR_PLAYER_SETTINGS_SIZE]);
/* Write an immutable exported settings record with durable atomic replacement. */
int topgear_player_settings_write_bytes(const char*,const uint8_t bytes[TOPGEAR_PLAYER_SETTINGS_SIZE]);
/* Read or update one frontend profile without a running ROM. Missing files
   expose the clean-install defaults; writes preserve the other profile and
   the in-game settings stored in the same record. */
int topgear_player_profile_file_read(const char*,unsigned,TopGearPlayerProfile*);
int topgear_player_profile_file_write(const char*,unsigned,const TopGearPlayerProfile*);
int topgear_settings_write_record(const char*,const void*,size_t);
int topgear_music_state_load_file(TopGearRecomp*,const char*,uint8_t cache[TOPGEAR_MUSIC_STATE_SIZE]);
#endif
