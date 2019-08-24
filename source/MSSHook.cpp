#include "MSSHook.h"
#include "FileSystem.h"

// Global addresses of IJL.dat functions
//IJL_VOID lpfnIJLGetLibVersion = NULL;
//IJL_VOID lpfnIJLInit = NULL;
//IJL_VOID lpfnIJLFree = NULL;
//IJL_VOID lpfnIJLRead = NULL;
//IJL_VOID lpfnIJLWrite = NULL;
//IJL_VOID lpfnIJLErrorStr = NULL;


/* Taken from Noginogi-Party; made by sokcuri */
IJL_VOID lpfn_AIL_get_preference = NULL;
IJL_VOID lpfn_AIL_lock = NULL;
IJL_VOID lpfn_AIL_unlock = NULL;
IJL_VOID lpfn_AIL_lock_mutex = NULL;
IJL_VOID lpfn_AIL_unlock_mutex = NULL;
IJL_VOID lpfn_AIL_get_timer_highest_delay = NULL;
IJL_VOID lpfn_DllMain = NULL;
IJL_VOID lpfn_RIB_load_static_provider_library = NULL;
IJL_VOID lpfnRIB_alloc_provider_handle = NULL;
IJL_VOID lpfnRIB_free_provider_handle = NULL;
IJL_VOID lpfnRIB_load_provider_library = NULL;
IJL_VOID lpfnRIB_free_provider_library = NULL;
IJL_VOID lpfnRIB_register_interface = NULL;
IJL_VOID lpfnRIB_request_interface = NULL;
IJL_VOID lpfnRIB_request_interface_entry = NULL;
IJL_VOID lpfnRIB_unregister_interface = NULL;
IJL_VOID lpfnRIB_enumerate_interface = NULL;
IJL_VOID lpfn_RIB_enumerate_providers = NULL;
IJL_VOID lpfnRIB_type_string = NULL;
IJL_VOID lpfnRIB_find_file_provider = NULL;
IJL_VOID lpfn_RIB_find_files_provider = NULL;
IJL_VOID lpfn_RIB_find_file_dec_provider = NULL;
IJL_VOID lpfn_RIB_find_provider = NULL;
IJL_VOID lpfn_RIB_load_application_providers = NULL;
IJL_VOID lpfn_RIB_set_provider_user_data = NULL;
IJL_VOID lpfn_RIB_provider_user_data = NULL;
IJL_VOID lpfn_RIB_set_provider_system_data = NULL;
IJL_VOID lpfn_RIB_provider_system_data = NULL;
IJL_VOID lpfnRIB_error = NULL;
IJL_VOID lpfn_AIL_set_file_async_callbacks = NULL;
IJL_VOID lpfn_AIL_set_file_callbacks = NULL;
IJL_VOID lpfn_AIL_list_DLS = NULL;
IJL_VOID lpfn_AIL_list_MIDI = NULL;
IJL_VOID lpfnstream_background = NULL;
IJL_VOID lpfn_AIL_ms_count = NULL;
IJL_VOID lpfn_AIL_us_count = NULL;
IJL_VOID lpfn_AIL_MMX_available = NULL;
IJL_VOID lpfnAIL_debug_printf = NULL;
IJL_VOID lpfn_AIL_startup = NULL;
IJL_VOID lpfn_AIL_shutdown = NULL;
IJL_VOID lpfn_AIL_HWND = NULL;
IJL_VOID lpfn_AIL_mem_alloc_lock = NULL;
IJL_VOID lpfn_AIL_mem_free_lock = NULL;
IJL_VOID lpfn_AIL_set_preference = NULL;
IJL_VOID lpfn_AIL_last_error = NULL;
IJL_VOID lpfn_AIL_set_error = NULL;
IJL_VOID lpfn_AIL_delay = NULL;
IJL_VOID lpfn_AIL_background = NULL;
IJL_VOID lpfn_AIL_register_timer = NULL;
IJL_VOID lpfn_AIL_set_timer_user = NULL;
IJL_VOID lpfn_AIL_set_timer_period = NULL;
IJL_VOID lpfn_AIL_set_timer_frequency = NULL;
IJL_VOID lpfn_AIL_set_timer_divisor = NULL;
IJL_VOID lpfn_AIL_start_timer = NULL;
IJL_VOID lpfn_AIL_start_all_timers = NULL;
IJL_VOID lpfn_AIL_stop_timer = NULL;
IJL_VOID lpfn_AIL_stop_all_timers = NULL;
IJL_VOID lpfn_AIL_release_timer_handle = NULL;
IJL_VOID lpfn_AIL_release_all_timers = NULL;
IJL_VOID lpfn_AIL_open_digital_driver = NULL;
IJL_VOID lpfn_AIL_close_digital_driver = NULL;
IJL_VOID lpfn_AIL_waveOutOpen = NULL;
IJL_VOID lpfn_AIL_waveOutClose = NULL;
IJL_VOID lpfn_AIL_digital_handle_release = NULL;
IJL_VOID lpfn_AIL_digital_handle_reacquire = NULL;
IJL_VOID lpfn_AIL_open_input = NULL;
IJL_VOID lpfn_AIL_close_input = NULL;
IJL_VOID lpfn_AIL_get_input_info = NULL;
IJL_VOID lpfn_AIL_set_input_state = NULL;
IJL_VOID lpfn_AIL_digital_CPU_percent = NULL;
IJL_VOID lpfn_AIL_digital_latency = NULL;
IJL_VOID lpfn_AIL_allocate_sample_handle = NULL;
IJL_VOID lpfn_AIL_allocate_file_sample = NULL;
IJL_VOID lpfn_AIL_release_sample_handle = NULL;
IJL_VOID lpfn_AIL_init_sample = NULL;
IJL_VOID lpfn_AIL_set_sample_file = NULL;
IJL_VOID lpfn_AIL_set_named_sample_file = NULL;
IJL_VOID lpfn_AIL_set_sample_processor = NULL;
IJL_VOID lpfn_AIL_set_stream_processor = NULL;
IJL_VOID lpfn_AIL_set_DLS_processor = NULL;
IJL_VOID lpfn_AIL_set_digital_driver_processor = NULL;
IJL_VOID lpfn_AIL_set_sample_address = NULL;
IJL_VOID lpfn_AIL_set_sample_type = NULL;
IJL_VOID lpfn_AIL_set_sample_adpcm_block_size = NULL;
IJL_VOID lpfn_AIL_start_sample = NULL;
IJL_VOID lpfn_AIL_stop_sample = NULL;
IJL_VOID lpfn_AIL_resume_sample = NULL;
IJL_VOID lpfn_AIL_end_sample = NULL;
IJL_VOID lpfn_AIL_set_sample_playback_rate = NULL;
IJL_VOID lpfn_AIL_set_sample_volume_pan = NULL;
IJL_VOID lpfn_AIL_set_sample_volume_levels = NULL;
IJL_VOID lpfn_AIL_set_sample_reverb_levels = NULL;
IJL_VOID lpfn_AIL_set_sample_low_pass_cut_off = NULL;
IJL_VOID lpfn_AIL_set_sample_loop_count = NULL;
IJL_VOID lpfn_AIL_set_sample_loop_block = NULL;
IJL_VOID lpfn_AIL_sample_status = NULL;
IJL_VOID lpfn_AIL_sample_playback_rate = NULL;
IJL_VOID lpfn_AIL_sample_volume_pan = NULL;
IJL_VOID lpfn_AIL_sample_volume_levels = NULL;
IJL_VOID lpfn_AIL_sample_reverb_levels = NULL;
IJL_VOID lpfn_AIL_sample_low_pass_cut_off = NULL;
IJL_VOID lpfn_AIL_sample_loop_count = NULL;
IJL_VOID lpfn_AIL_set_digital_master_volume_level = NULL;
IJL_VOID lpfn_AIL_digital_master_volume_level = NULL;
IJL_VOID lpfn_AIL_set_digital_master_reverb_levels = NULL;
IJL_VOID lpfn_AIL_set_digital_master_room_type = NULL;
IJL_VOID lpfn_AIL_digital_master_reverb_levels = NULL;
IJL_VOID lpfn_AIL_set_digital_master_reverb = NULL;
IJL_VOID lpfn_AIL_digital_master_reverb = NULL;
IJL_VOID lpfn_AIL_minimum_sample_buffer_size = NULL;
IJL_VOID lpfn_AIL_sample_buffer_ready = NULL;
IJL_VOID lpfn_AIL_load_sample_buffer = NULL;
IJL_VOID lpfn_AIL_sample_buffer_info = NULL;
IJL_VOID lpfn_AIL_sample_granularity = NULL;
IJL_VOID lpfn_AIL_set_sample_position = NULL;
IJL_VOID lpfn_AIL_sample_position = NULL;
IJL_VOID lpfn_AIL_register_SOB_callback = NULL;
IJL_VOID lpfn_AIL_register_EOB_callback = NULL;
IJL_VOID lpfn_AIL_register_EOS_callback = NULL;
IJL_VOID lpfn_AIL_register_EOF_callback = NULL;
IJL_VOID lpfn_AIL_set_sample_user_data = NULL;
IJL_VOID lpfn_AIL_sample_user_data = NULL;
IJL_VOID lpfn_AIL_active_sample_count = NULL;
IJL_VOID lpfn_AIL_digital_configuration = NULL;
IJL_VOID lpfn_AIL_get_DirectSound_info = NULL;
IJL_VOID lpfn_AIL_set_DirectSound_HWND = NULL;
IJL_VOID lpfn_AIL_open_XMIDI_driver = NULL;
IJL_VOID lpfn_AIL_close_XMIDI_driver = NULL;
IJL_VOID lpfn_AIL_midiOutOpen = NULL;
IJL_VOID lpfn_AIL_midiOutClose = NULL;
IJL_VOID lpfn_AIL_MIDI_handle_release = NULL;
IJL_VOID lpfn_AIL_MIDI_handle_reacquire = NULL;
IJL_VOID lpfn_AIL_allocate_sequence_handle = NULL;
IJL_VOID lpfn_AIL_release_sequence_handle = NULL;
IJL_VOID lpfn_AIL_init_sequence = NULL;
IJL_VOID lpfn_AIL_start_sequence = NULL;
IJL_VOID lpfn_AIL_stop_sequence = NULL;
IJL_VOID lpfn_AIL_resume_sequence = NULL;
IJL_VOID lpfn_AIL_end_sequence = NULL;
IJL_VOID lpfn_AIL_set_sequence_tempo = NULL;
IJL_VOID lpfn_AIL_set_sequence_volume = NULL;
IJL_VOID lpfn_AIL_set_sequence_loop_count = NULL;
IJL_VOID lpfn_AIL_sequence_status = NULL;
IJL_VOID lpfn_AIL_sequence_tempo = NULL;
IJL_VOID lpfn_AIL_sequence_volume = NULL;
IJL_VOID lpfn_AIL_sequence_loop_count = NULL;
IJL_VOID lpfn_AIL_set_XMIDI_master_volume = NULL;
IJL_VOID lpfn_AIL_XMIDI_master_volume = NULL;
IJL_VOID lpfn_AIL_active_sequence_count = NULL;
IJL_VOID lpfn_AIL_controller_value = NULL;
IJL_VOID lpfn_AIL_channel_notes = NULL;
IJL_VOID lpfn_AIL_sequence_position = NULL;
IJL_VOID lpfn_AIL_branch_index = NULL;
IJL_VOID lpfn_AIL_register_prefix_callback = NULL;
IJL_VOID lpfn_AIL_register_trigger_callback = NULL;
IJL_VOID lpfn_AIL_register_sequence_callback = NULL;
IJL_VOID lpfn_AIL_register_beat_callback = NULL;
IJL_VOID lpfn_AIL_register_event_callback = NULL;
IJL_VOID lpfn_AIL_register_timbre_callback = NULL;
IJL_VOID lpfn_AIL_set_sequence_user_data = NULL;
IJL_VOID lpfn_AIL_sequence_user_data = NULL;
IJL_VOID lpfn_AIL_register_ICA_array = NULL;
IJL_VOID lpfn_AIL_lock_channel = NULL;
IJL_VOID lpfn_AIL_release_channel = NULL;
IJL_VOID lpfn_AIL_map_sequence_channel = NULL;
IJL_VOID lpfn_AIL_true_sequence_channel = NULL;
IJL_VOID lpfn_AIL_send_channel_voice_message = NULL;
IJL_VOID lpfn_AIL_send_sysex_message = NULL;
IJL_VOID lpfn_AIL_create_wave_synthesizer = NULL;
IJL_VOID lpfn_AIL_destroy_wave_synthesizer = NULL;
IJL_VOID lpfn_AIL_file_error = NULL;
IJL_VOID lpfn_AIL_file_size = NULL;
IJL_VOID lpfn_AIL_file_read = NULL;
IJL_VOID lpfn_AIL_file_write = NULL;
IJL_VOID lpfn_AIL_WAV_file_write = NULL;
IJL_VOID lpfn_AIL_serve = NULL;
IJL_VOID lpfn_AIL_redbook_open = NULL;
IJL_VOID lpfn_AIL_redbook_open_drive = NULL;
IJL_VOID lpfn_AIL_redbook_close = NULL;
IJL_VOID lpfn_AIL_redbook_eject = NULL;
IJL_VOID lpfn_AIL_redbook_retract = NULL;
IJL_VOID lpfn_AIL_redbook_status = NULL;
IJL_VOID lpfn_AIL_redbook_tracks = NULL;
IJL_VOID lpfn_AIL_redbook_track = NULL;
IJL_VOID lpfn_AIL_redbook_track_info = NULL;
IJL_VOID lpfn_AIL_redbook_id = NULL;
IJL_VOID lpfn_AIL_redbook_position = NULL;
IJL_VOID lpfn_AIL_redbook_play = NULL;
IJL_VOID lpfn_AIL_redbook_stop = NULL;
IJL_VOID lpfn_AIL_redbook_pause = NULL;
IJL_VOID lpfn_AIL_redbook_resume = NULL;
IJL_VOID lpfn_AIL_redbook_volume_level = NULL;
IJL_VOID lpfn_AIL_redbook_set_volume_level = NULL;
IJL_VOID lpfn_AIL_quick_startup = NULL;
IJL_VOID lpfn_AIL_quick_shutdown = NULL;
IJL_VOID lpfn_AIL_quick_handles = NULL;
IJL_VOID lpfn_AIL_quick_load = NULL;
IJL_VOID lpfn_AIL_quick_load_mem = NULL;
IJL_VOID lpfn_AIL_quick_copy = NULL;
IJL_VOID lpfn_AIL_quick_unload = NULL;
IJL_VOID lpfn_AIL_quick_play = NULL;
IJL_VOID lpfn_AIL_quick_halt = NULL;
IJL_VOID lpfn_AIL_quick_status = NULL;
IJL_VOID lpfn_AIL_quick_load_and_play = NULL;
IJL_VOID lpfn_AIL_quick_set_speed = NULL;
IJL_VOID lpfn_AIL_quick_set_volume = NULL;
IJL_VOID lpfn_AIL_quick_set_reverb_levels = NULL;
IJL_VOID lpfn_AIL_quick_set_low_pass_cut_off = NULL;
IJL_VOID lpfn_AIL_open_stream = NULL;
IJL_VOID lpfn_AIL_close_stream = NULL;
IJL_VOID lpfn_AIL_service_stream = NULL;
IJL_VOID lpfn_AIL_start_stream = NULL;
IJL_VOID lpfn_AIL_pause_stream = NULL;
IJL_VOID lpfn_AIL_set_stream_volume_pan = NULL;
IJL_VOID lpfn_AIL_set_stream_volume_levels = NULL;
IJL_VOID lpfn_AIL_set_stream_reverb_levels = NULL;
IJL_VOID lpfn_AIL_set_stream_low_pass_cut_off = NULL;
IJL_VOID lpfn_AIL_stream_volume_pan = NULL;
IJL_VOID lpfn_AIL_stream_volume_levels = NULL;
IJL_VOID lpfn_AIL_stream_reverb_levels = NULL;
IJL_VOID lpfn_AIL_stream_low_pass_cut_off = NULL;
IJL_VOID lpfn_AIL_set_stream_playback_rate = NULL;
IJL_VOID lpfn_AIL_stream_playback_rate = NULL;
IJL_VOID lpfn_AIL_stream_loop_count = NULL;
IJL_VOID lpfn_AIL_set_stream_loop_block = NULL;
IJL_VOID lpfn_AIL_set_stream_loop_count = NULL;
IJL_VOID lpfn_AIL_stream_status = NULL;
IJL_VOID lpfn_AIL_set_stream_position = NULL;
IJL_VOID lpfn_AIL_stream_position = NULL;
IJL_VOID lpfn_AIL_stream_info = NULL;
IJL_VOID lpfn_AIL_register_stream_callback = NULL;
IJL_VOID lpfn_AIL_auto_service_stream = NULL;
IJL_VOID lpfn_AIL_set_stream_user_data = NULL;
IJL_VOID lpfn_AIL_stream_user_data = NULL;
IJL_VOID lpfn_AIL_DLS_open = NULL;
IJL_VOID lpfn_AIL_DLS_close = NULL;
IJL_VOID lpfn_AIL_DLS_load_file = NULL;
IJL_VOID lpfn_AIL_DLS_load_memory = NULL;
IJL_VOID lpfn_AIL_DLS_unload = NULL;
IJL_VOID lpfn_AIL_DLS_compact = NULL;
IJL_VOID lpfn_AIL_DLS_set_reverb_levels = NULL;
IJL_VOID lpfn_AIL_DLS_get_reverb_levels = NULL;
IJL_VOID lpfn_AIL_DLS_get_info = NULL;
IJL_VOID lpfn_AIL_set_sequence_ms_position = NULL;
IJL_VOID lpfn_AIL_sequence_ms_position = NULL;
IJL_VOID lpfn_AIL_sample_ms_position = NULL;
IJL_VOID lpfn_AIL_set_sample_ms_position = NULL;
IJL_VOID lpfn_AIL_stream_ms_position = NULL;
IJL_VOID lpfn_AIL_set_stream_ms_position = NULL;
IJL_VOID lpfn_AIL_quick_set_ms_position = NULL;
IJL_VOID lpfn_AIL_quick_ms_position = NULL;
IJL_VOID lpfn_AIL_quick_ms_length = NULL;
IJL_VOID lpfn_AIL_quick_type = NULL;
IJL_VOID lpfn_AIL_MIDI_to_XMI = NULL;
IJL_VOID lpfn_AIL_compress_ADPCM = NULL;
IJL_VOID lpfn_AIL_decompress_ADPCM = NULL;
IJL_VOID lpfn_AIL_WAV_info = NULL;
IJL_VOID lpfn_AIL_file_type = NULL;
IJL_VOID lpfn_AIL_find_DLS = NULL;
IJL_VOID lpfn_AIL_extract_DLS = NULL;
IJL_VOID lpfn_AIL_primary_digital_driver = NULL;
IJL_VOID lpfn_AIL_enumerate_filters = NULL;
IJL_VOID lpfn_AIL_open_filter = NULL;
IJL_VOID lpfn_AIL_close_filter = NULL;
IJL_VOID lpfn_AIL_enumerate_filter_attributes = NULL;
IJL_VOID lpfn_AIL_enumerate_filter_sample_attribute = NULL;
IJL_VOID lpfn_AIL_filter_attribute = NULL;
IJL_VOID lpfn_AIL_filter_sample_attribute = NULL;
IJL_VOID lpfn_AIL_filter_stream_attribute = NULL;
IJL_VOID lpfn_AIL_filter_DLS_attribute = NULL;
IJL_VOID lpfn_AIL_set_filter_preference = NULL;
IJL_VOID lpfn_AIL_set_filter_sample_preference = NULL;
IJL_VOID lpfn_AIL_set_filter_stream_preference = NULL;
IJL_VOID lpfn_AIL_set_filter_DLS_preference = NULL;
IJL_VOID lpfn_AIL_enumerate_3D_providers = NULL;
IJL_VOID lpfn_AIL_open_3D_provider = NULL;
IJL_VOID lpfn_AIL_close_3D_provider = NULL;
IJL_VOID lpfn_AIL_enumerate_3D_provider_attributes = NULL;
IJL_VOID lpfn_AIL_enumerate_3D_sample_attributes = NULL;
IJL_VOID lpfn_AIL_3D_provider_attribute = NULL;
IJL_VOID lpfn_AIL_3D_sample_attribute = NULL;
IJL_VOID lpfn_AIL_set_3D_provider_preference = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_preference = NULL;
IJL_VOID lpfn_AIL_allocate_3D_sample_handle = NULL;
IJL_VOID lpfn_AIL_release_3D_sample_handle = NULL;
IJL_VOID lpfn_AIL_start_3D_sample = NULL;
IJL_VOID lpfn_AIL_stop_3D_sample = NULL;
IJL_VOID lpfn_AIL_resume_3D_sample = NULL;
IJL_VOID lpfn_AIL_end_3D_sample = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_info = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_file = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_volume = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_playback_rate = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_offset = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_loop_count = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_loop_block = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_obstruction = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_exclusion = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_occlusion = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_cone = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_effects_level = NULL;
IJL_VOID lpfn_AIL_register_3D_EOS_callback = NULL;
IJL_VOID lpfn_AIL_3D_sample_obstruction = NULL;
IJL_VOID lpfn_AIL_3D_sample_exclusion = NULL;
IJL_VOID lpfn_AIL_3D_sample_occlusion = NULL;
IJL_VOID lpfn_AIL_3D_sample_cone = NULL;
IJL_VOID lpfn_AIL_3D_sample_effects_level = NULL;
IJL_VOID lpfn_AIL_3D_sample_status = NULL;
IJL_VOID lpfn_AIL_3D_sample_volume = NULL;
IJL_VOID lpfn_AIL_3D_sample_playback_rate = NULL;
IJL_VOID lpfn_AIL_3D_sample_offset = NULL;
IJL_VOID lpfn_AIL_3D_sample_length = NULL;
IJL_VOID lpfn_AIL_3D_sample_loop_count = NULL;
IJL_VOID lpfn_AIL_set_3D_sample_distances = NULL;
IJL_VOID lpfn_AIL_3D_sample_distances = NULL;
IJL_VOID lpfn_AIL_set_3D_user_data = NULL;
IJL_VOID lpfn_AIL_3D_user_data = NULL;
IJL_VOID lpfn_AIL_active_3D_sample_count = NULL;
IJL_VOID lpfn_AIL_3D_room_type = NULL;
IJL_VOID lpfn_AIL_set_3D_room_type = NULL;
IJL_VOID lpfn_AIL_3D_speaker_type = NULL;
IJL_VOID lpfn_AIL_set_3D_speaker_type = NULL;
IJL_VOID lpfn_AIL_3D_rolloff_factor = NULL;
IJL_VOID lpfn_AIL_set_3D_rolloff_factor = NULL;
IJL_VOID lpfn_AIL_3D_doppler_factor = NULL;
IJL_VOID lpfn_AIL_set_3D_doppler_factor = NULL;
IJL_VOID lpfn_AIL_3D_distance_factor = NULL;
IJL_VOID lpfn_AIL_set_3D_distance_factor = NULL;
IJL_VOID lpfn_AIL_open_3D_listener = NULL;
IJL_VOID lpfn_AIL_close_3D_listener = NULL;
IJL_VOID lpfn_AIL_open_3D_object = NULL;
IJL_VOID lpfn_AIL_close_3D_object = NULL;
IJL_VOID lpfn_AIL_set_3D_position = NULL;
IJL_VOID lpfn_AIL_set_3D_velocity = NULL;
IJL_VOID lpfn_AIL_set_3D_velocity_vector = NULL;
IJL_VOID lpfn_AIL_set_3D_orientation = NULL;
IJL_VOID lpfn_AIL_3D_position = NULL;
IJL_VOID lpfn_AIL_3D_velocity = NULL;
IJL_VOID lpfn_AIL_3D_orientation = NULL;
IJL_VOID lpfn_AIL_update_3D_position = NULL;
IJL_VOID lpfn_AIL_auto_update_3D_position = NULL;
IJL_VOID lpfn_AIL_size_processed_digital_audio = NULL;
IJL_VOID lpfn_AIL_process_digital_audio = NULL;
IJL_VOID lpfn_AIL_merge_DLS_with_XMI = NULL;
IJL_VOID lpfn_AIL_compress_DLS = NULL;
IJL_VOID lpfn_AIL_filter_DLS_with_XMI = NULL;
IJL_VOID lpfn_AIL_compress_ASI = NULL;
IJL_VOID lpfn_AIL_decompress_ASI = NULL;
IJL_VOID lpfn_AIL_request_EOB_ASI_reset = NULL;
IJL_VOID lpfn_AIL_set_redist_directory = NULL;
IJL_VOID lpfn_MIX_RIB_MAIN = NULL;
IJL_VOID lpfn_AIL_mem_use_malloc = NULL;
IJL_VOID lpfn_AIL_mem_use_free = NULL;
IJL_VOID lpfnAIL_sprintf = NULL;
IJL_VOID lpfnDLSMSSOpen = NULL;
IJL_VOID lpfnDLSClose = NULL;
IJL_VOID lpfnDLSLoadFile = NULL;
IJL_VOID lpfnDLSLoadMemFile = NULL;
IJL_VOID lpfnDLSGetInfo = NULL;
IJL_VOID lpfnDLSCompactMemory = NULL;
IJL_VOID lpfnDLSUnloadAll = NULL;
IJL_VOID lpfnDLSUnloadFile = NULL;
IJL_VOID lpfnDLSSetAttribute = NULL;
IJL_VOID lpfn_DLSMSSGetCPU = NULL;


// Screenshot quality mod setting
DWORD ssQuality = 75;

//-------------------------------------------
// Methods

CMSSHook::~CMSSHook()
{
	if ( hIJL != NULL ) {
		FreeLibrary( hIJL );
	}
}

bool CMSSHook::Hook()
{
	/*wstring ijlDat=GetCurPath();
	ijlDat+=L"\\ijl15.dat";
	
	hIJL = LoadLibrary(ijlDat.c_str());
	if (hIJL == NULL)
	{
		DebugLog("Failed to load IJL.dat.\n");
		WriteLog("IJL hook installation failed.\n");
		return false;
	}

	lpfnIJLGetLibVersion	= (IJL_VOID)GetProcAddress(hIJL, "ijlGetLibVersion");
	lpfnIJLInit				= (IJL_VOID)GetProcAddress(hIJL, "ijlInit");
	lpfnIJLFree				= (IJL_VOID)GetProcAddress(hIJL, "ijlFree");
	lpfnIJLRead				= (IJL_VOID)GetProcAddress(hIJL, "ijlRead");
	lpfnIJLWrite			= (IJL_VOID)GetProcAddress(hIJL, "ijlWrite");
	lpfnIJLErrorStr			= (IJL_VOID)GetProcAddress(hIJL, "ijlErrorStr");

	if (!lpfnIJLGetLibVersion ||
		!lpfnIJLInit ||
		!lpfnIJLFree ||
		!lpfnIJLRead ||
		!lpfnIJLWrite ||
		!lpfnIJLErrorStr )
	{
		DebugLog("Failed to get IJL.dat export addresses.\n");
		WriteLog("IJL hook installation failed.\n");
		return false;
	}
	WriteLog("IJL hook installation successful.\n");
	*/
	wstring dllPath;
	dllPath += GetCurPath();
	dllPath += L"\\Mss32.DLX";

	DebugLog("%ls���� Mss32.dlx ������ �ε��մϴ�.\n", GetCurPath().c_str());
	DebugLog("�αװ� ���⼭ ����ٸ� Mss32.dlx ������ �ִ��� Ȯ�����ּ���.\n");

	hIJL = LoadLibrary(dllPath.c_str());
	if (hIJL == NULL)
	{
		DebugLog("Mss32.DLX ���� �ε��� �����߽��ϴ�.\n");
		WriteLog("Mss32 Hook ��ġ�� �����߽��ϴ�.\n");
		return false;
	}

	WriteLog("Mss32 Hook ��ġ�� �����մϴ�.\n");


	lpfn_AIL_get_preference = (IJL_VOID)GetProcAddress(hIJL, "_AIL_get_preference@4");
	lpfn_AIL_lock = (IJL_VOID)GetProcAddress(hIJL, "_AIL_lock@0");
	lpfn_AIL_unlock = (IJL_VOID)GetProcAddress(hIJL, "_AIL_unlock@0");
	lpfn_AIL_lock_mutex = (IJL_VOID)GetProcAddress(hIJL, "_AIL_lock_mutex@0");
	lpfn_AIL_unlock_mutex = (IJL_VOID)GetProcAddress(hIJL, "_AIL_unlock_mutex@0");
	lpfn_AIL_get_timer_highest_delay = (IJL_VOID)GetProcAddress(hIJL, "_AIL_get_timer_highest_delay@0");
	lpfn_DllMain = (IJL_VOID)GetProcAddress(hIJL, "_DllMain@12");
	lpfn_RIB_load_static_provider_library = (IJL_VOID)GetProcAddress(hIJL, "_RIB_load_static_provider_library@8");
	lpfnRIB_alloc_provider_handle = (IJL_VOID)GetProcAddress(hIJL, "RIB_alloc_provider_handle");
	lpfnRIB_free_provider_handle = (IJL_VOID)GetProcAddress(hIJL, "RIB_free_provider_handle");
	lpfnRIB_load_provider_library = (IJL_VOID)GetProcAddress(hIJL, "RIB_load_provider_library");
	lpfnRIB_free_provider_library = (IJL_VOID)GetProcAddress(hIJL, "RIB_free_provider_library");
	lpfnRIB_register_interface = (IJL_VOID)GetProcAddress(hIJL, "RIB_register_interface");
	lpfnRIB_request_interface = (IJL_VOID)GetProcAddress(hIJL, "RIB_request_interface");
	lpfnRIB_request_interface_entry = (IJL_VOID)GetProcAddress(hIJL, "RIB_request_interface_entry");
	lpfnRIB_unregister_interface = (IJL_VOID)GetProcAddress(hIJL, "RIB_unregister_interface");
	lpfnRIB_enumerate_interface = (IJL_VOID)GetProcAddress(hIJL, "RIB_enumerate_interface");
	lpfn_RIB_enumerate_providers = (IJL_VOID)GetProcAddress(hIJL, "_RIB_enumerate_providers@12");
	lpfnRIB_type_string = (IJL_VOID)GetProcAddress(hIJL, "RIB_type_string");
	lpfnRIB_find_file_provider = (IJL_VOID)GetProcAddress(hIJL, "RIB_find_file_provider");
	lpfn_RIB_find_files_provider = (IJL_VOID)GetProcAddress(hIJL, "_RIB_find_files_provider@20");
	lpfn_RIB_find_file_dec_provider = (IJL_VOID)GetProcAddress(hIJL, "_RIB_find_file_dec_provider@20");
	lpfn_RIB_find_provider = (IJL_VOID)GetProcAddress(hIJL, "_RIB_find_provider@12");
	lpfn_RIB_load_application_providers = (IJL_VOID)GetProcAddress(hIJL, "_RIB_load_application_providers@4");
	lpfn_RIB_set_provider_user_data = (IJL_VOID)GetProcAddress(hIJL, "_RIB_set_provider_user_data@12");
	lpfn_RIB_provider_user_data = (IJL_VOID)GetProcAddress(hIJL, "_RIB_provider_user_data@8");
	lpfn_RIB_set_provider_system_data = (IJL_VOID)GetProcAddress(hIJL, "_RIB_set_provider_system_data@12");
	lpfn_RIB_provider_system_data = (IJL_VOID)GetProcAddress(hIJL, "_RIB_provider_system_data@8");
	lpfnRIB_error = (IJL_VOID)GetProcAddress(hIJL, "RIB_error");
	lpfn_AIL_set_file_async_callbacks = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_file_async_callbacks@20");
	lpfn_AIL_set_file_callbacks = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_file_callbacks@16");
	lpfn_AIL_list_DLS = (IJL_VOID)GetProcAddress(hIJL, "_AIL_list_DLS@20");
	lpfn_AIL_list_MIDI = (IJL_VOID)GetProcAddress(hIJL, "_AIL_list_MIDI@20");
	lpfnstream_background = (IJL_VOID)GetProcAddress(hIJL, "stream_background");
	lpfn_AIL_ms_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_ms_count@0");
	lpfn_AIL_us_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_us_count@0");
	lpfn_AIL_MMX_available = (IJL_VOID)GetProcAddress(hIJL, "_AIL_MMX_available@0");
	lpfnAIL_debug_printf = (IJL_VOID)GetProcAddress(hIJL, "AIL_debug_printf");
	lpfn_AIL_startup = (IJL_VOID)GetProcAddress(hIJL, "_AIL_startup@0");
	lpfn_AIL_shutdown = (IJL_VOID)GetProcAddress(hIJL, "_AIL_shutdown@0");
	lpfn_AIL_HWND = (IJL_VOID)GetProcAddress(hIJL, "_AIL_HWND@0");
	lpfn_AIL_mem_alloc_lock = (IJL_VOID)GetProcAddress(hIJL, "_AIL_mem_alloc_lock@4");
	lpfn_AIL_mem_free_lock = (IJL_VOID)GetProcAddress(hIJL, "_AIL_mem_free_lock@4");
	lpfn_AIL_set_preference = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_preference@8");
	lpfn_AIL_last_error = (IJL_VOID)GetProcAddress(hIJL, "_AIL_last_error@0");
	lpfn_AIL_set_error = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_error@4");
	lpfn_AIL_delay = (IJL_VOID)GetProcAddress(hIJL, "_AIL_delay@4");
	lpfn_AIL_background = (IJL_VOID)GetProcAddress(hIJL, "_AIL_background@0");
	lpfn_AIL_register_timer = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_timer@4");
	lpfn_AIL_set_timer_user = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_timer_user@8");
	lpfn_AIL_set_timer_period = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_timer_period@8");
	lpfn_AIL_set_timer_frequency = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_timer_frequency@8");
	lpfn_AIL_set_timer_divisor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_timer_divisor@8");
	lpfn_AIL_start_timer = (IJL_VOID)GetProcAddress(hIJL, "_AIL_start_timer@4");
	lpfn_AIL_start_all_timers = (IJL_VOID)GetProcAddress(hIJL, "_AIL_start_all_timers@0");
	lpfn_AIL_stop_timer = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stop_timer@4");
	lpfn_AIL_stop_all_timers = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stop_all_timers@0");
	lpfn_AIL_release_timer_handle = (IJL_VOID)GetProcAddress(hIJL, "_AIL_release_timer_handle@4");
	lpfn_AIL_release_all_timers = (IJL_VOID)GetProcAddress(hIJL, "_AIL_release_all_timers@0");
	lpfn_AIL_open_digital_driver = (IJL_VOID)GetProcAddress(hIJL, "_AIL_open_digital_driver@16");
	lpfn_AIL_close_digital_driver = (IJL_VOID)GetProcAddress(hIJL, "_AIL_close_digital_driver@4");
	lpfn_AIL_waveOutOpen = (IJL_VOID)GetProcAddress(hIJL, "_AIL_waveOutOpen@16");
	lpfn_AIL_waveOutClose = (IJL_VOID)GetProcAddress(hIJL, "_AIL_waveOutClose@4");
	lpfn_AIL_digital_handle_release = (IJL_VOID)GetProcAddress(hIJL, "_AIL_digital_handle_release@4");
	lpfn_AIL_digital_handle_reacquire = (IJL_VOID)GetProcAddress(hIJL, "_AIL_digital_handle_reacquire@4");
	lpfn_AIL_open_input = (IJL_VOID)GetProcAddress(hIJL, "_AIL_open_input@4");
	lpfn_AIL_close_input = (IJL_VOID)GetProcAddress(hIJL, "_AIL_close_input@4");
	lpfn_AIL_get_input_info = (IJL_VOID)GetProcAddress(hIJL, "_AIL_get_input_info@4");
	lpfn_AIL_set_input_state = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_input_state@8");
	lpfn_AIL_digital_CPU_percent = (IJL_VOID)GetProcAddress(hIJL, "_AIL_digital_CPU_percent@4");
	lpfn_AIL_digital_latency = (IJL_VOID)GetProcAddress(hIJL, "_AIL_digital_latency@4");
	lpfn_AIL_allocate_sample_handle = (IJL_VOID)GetProcAddress(hIJL, "_AIL_allocate_sample_handle@4");
	lpfn_AIL_allocate_file_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_allocate_file_sample@12");
	lpfn_AIL_release_sample_handle = (IJL_VOID)GetProcAddress(hIJL, "_AIL_release_sample_handle@4");
	lpfn_AIL_init_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_init_sample@4");
	lpfn_AIL_set_sample_file = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_file@12");
	lpfn_AIL_set_named_sample_file = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_named_sample_file@20");
	lpfn_AIL_set_sample_processor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_processor@12");
	lpfn_AIL_set_stream_processor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_processor@12");
	lpfn_AIL_set_DLS_processor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_DLS_processor@12");
	lpfn_AIL_set_digital_driver_processor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_digital_driver_processor@12");
	lpfn_AIL_set_sample_address = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_address@12");
	lpfn_AIL_set_sample_type = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_type@12");
	lpfn_AIL_set_sample_adpcm_block_size = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_adpcm_block_size@8");
	lpfn_AIL_start_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_start_sample@4");
	lpfn_AIL_stop_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stop_sample@4");
	lpfn_AIL_resume_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_resume_sample@4");
	lpfn_AIL_end_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_end_sample@4");
	lpfn_AIL_set_sample_playback_rate = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_playback_rate@8");
	lpfn_AIL_set_sample_volume_pan = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_volume_pan@12");
	lpfn_AIL_set_sample_volume_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_volume_levels@12");
	lpfn_AIL_set_sample_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_reverb_levels@12");
	lpfn_AIL_set_sample_low_pass_cut_off = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_low_pass_cut_off@8");
	lpfn_AIL_set_sample_loop_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_loop_count@8");
	lpfn_AIL_set_sample_loop_block = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_loop_block@12");
	lpfn_AIL_sample_status = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_status@4");
	lpfn_AIL_sample_playback_rate = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_playback_rate@4");
	lpfn_AIL_sample_volume_pan = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_volume_pan@12");
	lpfn_AIL_sample_volume_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_volume_levels@12");
	lpfn_AIL_sample_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_reverb_levels@12");
	lpfn_AIL_sample_low_pass_cut_off = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_low_pass_cut_off@4");
	lpfn_AIL_sample_loop_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_loop_count@4");
	lpfn_AIL_set_digital_master_volume_level = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_digital_master_volume_level@8");
	lpfn_AIL_digital_master_volume_level = (IJL_VOID)GetProcAddress(hIJL, "_AIL_digital_master_volume_level@4");
	lpfn_AIL_set_digital_master_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_digital_master_reverb_levels@12");
	lpfn_AIL_set_digital_master_room_type = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_digital_master_room_type@8");
	lpfn_AIL_digital_master_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_digital_master_reverb_levels@12");
	lpfn_AIL_set_digital_master_reverb = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_digital_master_reverb@16");
	lpfn_AIL_digital_master_reverb = (IJL_VOID)GetProcAddress(hIJL, "_AIL_digital_master_reverb@16");
	lpfn_AIL_minimum_sample_buffer_size = (IJL_VOID)GetProcAddress(hIJL, "_AIL_minimum_sample_buffer_size@12");
	lpfn_AIL_sample_buffer_ready = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_buffer_ready@4");
	lpfn_AIL_load_sample_buffer = (IJL_VOID)GetProcAddress(hIJL, "_AIL_load_sample_buffer@16");
	lpfn_AIL_sample_buffer_info = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_buffer_info@20");
	lpfn_AIL_sample_granularity = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_granularity@4");
	lpfn_AIL_set_sample_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_position@8");
	lpfn_AIL_sample_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_position@4");
	lpfn_AIL_register_SOB_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_SOB_callback@8");
	lpfn_AIL_register_EOB_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_EOB_callback@8");
	lpfn_AIL_register_EOS_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_EOS_callback@8");
	lpfn_AIL_register_EOF_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_EOF_callback@8");
	lpfn_AIL_set_sample_user_data = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_user_data@12");
	lpfn_AIL_sample_user_data = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_user_data@8");
	lpfn_AIL_active_sample_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_active_sample_count@4");
	lpfn_AIL_digital_configuration = (IJL_VOID)GetProcAddress(hIJL, "_AIL_digital_configuration@16");
	lpfn_AIL_get_DirectSound_info = (IJL_VOID)GetProcAddress(hIJL, "_AIL_get_DirectSound_info@12");
	lpfn_AIL_set_DirectSound_HWND = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_DirectSound_HWND@8");
	lpfn_AIL_open_XMIDI_driver = (IJL_VOID)GetProcAddress(hIJL, "_AIL_open_XMIDI_driver@4");
	lpfn_AIL_close_XMIDI_driver = (IJL_VOID)GetProcAddress(hIJL, "_AIL_close_XMIDI_driver@4");
	lpfn_AIL_midiOutOpen = (IJL_VOID)GetProcAddress(hIJL, "_AIL_midiOutOpen@12");
	lpfn_AIL_midiOutClose = (IJL_VOID)GetProcAddress(hIJL, "_AIL_midiOutClose@4");
	lpfn_AIL_MIDI_handle_release = (IJL_VOID)GetProcAddress(hIJL, "_AIL_MIDI_handle_release@4");
	lpfn_AIL_MIDI_handle_reacquire = (IJL_VOID)GetProcAddress(hIJL, "_AIL_MIDI_handle_reacquire@4");
	lpfn_AIL_allocate_sequence_handle = (IJL_VOID)GetProcAddress(hIJL, "_AIL_allocate_sequence_handle@4");
	lpfn_AIL_release_sequence_handle = (IJL_VOID)GetProcAddress(hIJL, "_AIL_release_sequence_handle@4");
	lpfn_AIL_init_sequence = (IJL_VOID)GetProcAddress(hIJL, "_AIL_init_sequence@12");
	lpfn_AIL_start_sequence = (IJL_VOID)GetProcAddress(hIJL, "_AIL_start_sequence@4");
	lpfn_AIL_stop_sequence = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stop_sequence@4");
	lpfn_AIL_resume_sequence = (IJL_VOID)GetProcAddress(hIJL, "_AIL_resume_sequence@4");
	lpfn_AIL_end_sequence = (IJL_VOID)GetProcAddress(hIJL, "_AIL_end_sequence@4");
	lpfn_AIL_set_sequence_tempo = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sequence_tempo@12");
	lpfn_AIL_set_sequence_volume = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sequence_volume@12");
	lpfn_AIL_set_sequence_loop_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sequence_loop_count@8");
	lpfn_AIL_sequence_status = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sequence_status@4");
	lpfn_AIL_sequence_tempo = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sequence_tempo@4");
	lpfn_AIL_sequence_volume = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sequence_volume@4");
	lpfn_AIL_sequence_loop_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sequence_loop_count@4");
	lpfn_AIL_set_XMIDI_master_volume = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_XMIDI_master_volume@8");
	lpfn_AIL_XMIDI_master_volume = (IJL_VOID)GetProcAddress(hIJL, "_AIL_XMIDI_master_volume@4");
	lpfn_AIL_active_sequence_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_active_sequence_count@4");
	lpfn_AIL_controller_value = (IJL_VOID)GetProcAddress(hIJL, "_AIL_controller_value@12");
	lpfn_AIL_channel_notes = (IJL_VOID)GetProcAddress(hIJL, "_AIL_channel_notes@8");
	lpfn_AIL_sequence_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sequence_position@12");
	lpfn_AIL_branch_index = (IJL_VOID)GetProcAddress(hIJL, "_AIL_branch_index@8");
	lpfn_AIL_register_prefix_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_prefix_callback@8");
	lpfn_AIL_register_trigger_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_trigger_callback@8");
	lpfn_AIL_register_sequence_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_sequence_callback@8");
	lpfn_AIL_register_beat_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_beat_callback@8");
	lpfn_AIL_register_event_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_event_callback@8");
	lpfn_AIL_register_timbre_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_timbre_callback@8");
	lpfn_AIL_set_sequence_user_data = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sequence_user_data@12");
	lpfn_AIL_sequence_user_data = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sequence_user_data@8");
	lpfn_AIL_register_ICA_array = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_ICA_array@8");
	lpfn_AIL_lock_channel = (IJL_VOID)GetProcAddress(hIJL, "_AIL_lock_channel@4");
	lpfn_AIL_release_channel = (IJL_VOID)GetProcAddress(hIJL, "_AIL_release_channel@8");
	lpfn_AIL_map_sequence_channel = (IJL_VOID)GetProcAddress(hIJL, "_AIL_map_sequence_channel@12");
	lpfn_AIL_true_sequence_channel = (IJL_VOID)GetProcAddress(hIJL, "_AIL_true_sequence_channel@8");
	lpfn_AIL_send_channel_voice_message = (IJL_VOID)GetProcAddress(hIJL, "_AIL_send_channel_voice_message@20");
	lpfn_AIL_send_sysex_message = (IJL_VOID)GetProcAddress(hIJL, "_AIL_send_sysex_message@8");
	lpfn_AIL_create_wave_synthesizer = (IJL_VOID)GetProcAddress(hIJL, "_AIL_create_wave_synthesizer@16");
	lpfn_AIL_destroy_wave_synthesizer = (IJL_VOID)GetProcAddress(hIJL, "_AIL_destroy_wave_synthesizer@4");
	lpfn_AIL_file_error = (IJL_VOID)GetProcAddress(hIJL, "_AIL_file_error@0");
	lpfn_AIL_file_size = (IJL_VOID)GetProcAddress(hIJL, "_AIL_file_size@4");
	lpfn_AIL_file_read = (IJL_VOID)GetProcAddress(hIJL, "_AIL_file_read@8");
	lpfn_AIL_file_write = (IJL_VOID)GetProcAddress(hIJL, "_AIL_file_write@12");
	lpfn_AIL_WAV_file_write = (IJL_VOID)GetProcAddress(hIJL, "_AIL_WAV_file_write@20");
	lpfn_AIL_serve = (IJL_VOID)GetProcAddress(hIJL, "_AIL_serve@0");
	lpfn_AIL_redbook_open = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_open@4");
	lpfn_AIL_redbook_open_drive = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_open_drive@4");
	lpfn_AIL_redbook_close = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_close@4");
	lpfn_AIL_redbook_eject = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_eject@4");
	lpfn_AIL_redbook_retract = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_retract@4");
	lpfn_AIL_redbook_status = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_status@4");
	lpfn_AIL_redbook_tracks = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_tracks@4");
	lpfn_AIL_redbook_track = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_track@4");
	lpfn_AIL_redbook_track_info = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_track_info@16");
	lpfn_AIL_redbook_id = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_id@4");
	lpfn_AIL_redbook_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_position@4");
	lpfn_AIL_redbook_play = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_play@12");
	lpfn_AIL_redbook_stop = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_stop@4");
	lpfn_AIL_redbook_pause = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_pause@4");
	lpfn_AIL_redbook_resume = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_resume@4");
	lpfn_AIL_redbook_volume_level = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_volume_level@4");
	lpfn_AIL_redbook_set_volume_level = (IJL_VOID)GetProcAddress(hIJL, "_AIL_redbook_set_volume_level@8");
	lpfn_AIL_quick_startup = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_startup@20");
	lpfn_AIL_quick_shutdown = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_shutdown@0");
	lpfn_AIL_quick_handles = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_handles@12");
	lpfn_AIL_quick_load = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_load@4");
	lpfn_AIL_quick_load_mem = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_load_mem@8");
	lpfn_AIL_quick_copy = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_copy@4");
	lpfn_AIL_quick_unload = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_unload@4");
	lpfn_AIL_quick_play = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_play@8");
	lpfn_AIL_quick_halt = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_halt@4");
	lpfn_AIL_quick_status = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_status@4");
	lpfn_AIL_quick_load_and_play = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_load_and_play@12");
	lpfn_AIL_quick_set_speed = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_set_speed@8");
	lpfn_AIL_quick_set_volume = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_set_volume@12");
	lpfn_AIL_quick_set_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_set_reverb_levels@12");
	lpfn_AIL_quick_set_low_pass_cut_off = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_set_low_pass_cut_off@8");
	lpfn_AIL_open_stream = (IJL_VOID)GetProcAddress(hIJL, "_AIL_open_stream@12");
	lpfn_AIL_close_stream = (IJL_VOID)GetProcAddress(hIJL, "_AIL_close_stream@4");
	lpfn_AIL_service_stream = (IJL_VOID)GetProcAddress(hIJL, "_AIL_service_stream@8");
	lpfn_AIL_start_stream = (IJL_VOID)GetProcAddress(hIJL, "_AIL_start_stream@4");
	lpfn_AIL_pause_stream = (IJL_VOID)GetProcAddress(hIJL, "_AIL_pause_stream@8");
	lpfn_AIL_set_stream_volume_pan = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_volume_pan@12");
	lpfn_AIL_set_stream_volume_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_volume_levels@12");
	lpfn_AIL_set_stream_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_reverb_levels@12");
	lpfn_AIL_set_stream_low_pass_cut_off = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_low_pass_cut_off@8");
	lpfn_AIL_stream_volume_pan = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_volume_pan@12");
	lpfn_AIL_stream_volume_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_volume_levels@12");
	lpfn_AIL_stream_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_reverb_levels@12");
	lpfn_AIL_stream_low_pass_cut_off = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_low_pass_cut_off@4");
	lpfn_AIL_set_stream_playback_rate = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_playback_rate@8");
	lpfn_AIL_stream_playback_rate = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_playback_rate@4");
	lpfn_AIL_stream_loop_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_loop_count@4");
	lpfn_AIL_set_stream_loop_block = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_loop_block@12");
	lpfn_AIL_set_stream_loop_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_loop_count@8");
	lpfn_AIL_stream_status = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_status@4");
	lpfn_AIL_set_stream_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_position@8");
	lpfn_AIL_stream_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_position@4");
	lpfn_AIL_stream_info = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_info@20");
	lpfn_AIL_register_stream_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_stream_callback@8");
	lpfn_AIL_auto_service_stream = (IJL_VOID)GetProcAddress(hIJL, "_AIL_auto_service_stream@8");
	lpfn_AIL_set_stream_user_data = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_user_data@12");
	lpfn_AIL_stream_user_data = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_user_data@8");
	lpfn_AIL_DLS_open = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_open@28");
	lpfn_AIL_DLS_close = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_close@8");
	lpfn_AIL_DLS_load_file = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_load_file@12");
	lpfn_AIL_DLS_load_memory = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_load_memory@12");
	lpfn_AIL_DLS_unload = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_unload@8");
	lpfn_AIL_DLS_compact = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_compact@4");
	lpfn_AIL_DLS_set_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_set_reverb_levels@12");
	lpfn_AIL_DLS_get_reverb_levels = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_get_reverb_levels@12");
	lpfn_AIL_DLS_get_info = (IJL_VOID)GetProcAddress(hIJL, "_AIL_DLS_get_info@12");
	lpfn_AIL_set_sequence_ms_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sequence_ms_position@8");
	lpfn_AIL_sequence_ms_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sequence_ms_position@12");
	lpfn_AIL_sample_ms_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_sample_ms_position@12");
	lpfn_AIL_set_sample_ms_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_sample_ms_position@8");
	lpfn_AIL_stream_ms_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stream_ms_position@12");
	lpfn_AIL_set_stream_ms_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_stream_ms_position@8");
	lpfn_AIL_quick_set_ms_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_set_ms_position@8");
	lpfn_AIL_quick_ms_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_ms_position@4");
	lpfn_AIL_quick_ms_length = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_ms_length@4");
	lpfn_AIL_quick_type = (IJL_VOID)GetProcAddress(hIJL, "_AIL_quick_type@4");
	lpfn_AIL_MIDI_to_XMI = (IJL_VOID)GetProcAddress(hIJL, "_AIL_MIDI_to_XMI@20");
	lpfn_AIL_compress_ADPCM = (IJL_VOID)GetProcAddress(hIJL, "_AIL_compress_ADPCM@12");
	lpfn_AIL_decompress_ADPCM = (IJL_VOID)GetProcAddress(hIJL, "_AIL_decompress_ADPCM@12");
	lpfn_AIL_WAV_info = (IJL_VOID)GetProcAddress(hIJL, "_AIL_WAV_info@8");
	lpfn_AIL_file_type = (IJL_VOID)GetProcAddress(hIJL, "_AIL_file_type@8");
	lpfn_AIL_find_DLS = (IJL_VOID)GetProcAddress(hIJL, "_AIL_find_DLS@24");
	lpfn_AIL_extract_DLS = (IJL_VOID)GetProcAddress(hIJL, "_AIL_extract_DLS@28");
	lpfn_AIL_primary_digital_driver = (IJL_VOID)GetProcAddress(hIJL, "_AIL_primary_digital_driver@4");
	lpfn_AIL_enumerate_filters = (IJL_VOID)GetProcAddress(hIJL, "_AIL_enumerate_filters@12");
	lpfn_AIL_open_filter = (IJL_VOID)GetProcAddress(hIJL, "_AIL_open_filter@8");
	lpfn_AIL_close_filter = (IJL_VOID)GetProcAddress(hIJL, "_AIL_close_filter@4");
	lpfn_AIL_enumerate_filter_attributes = (IJL_VOID)GetProcAddress(hIJL, "_AIL_enumerate_filter_attributes@12");
	lpfn_AIL_enumerate_filter_sample_attribute = (IJL_VOID)GetProcAddress(hIJL, "_AIL_enumerate_filter_sample_attributes@12");
	lpfn_AIL_filter_attribute = (IJL_VOID)GetProcAddress(hIJL, "_AIL_filter_attribute@12");
	lpfn_AIL_filter_sample_attribute = (IJL_VOID)GetProcAddress(hIJL, "_AIL_filter_sample_attribute@12");
	lpfn_AIL_filter_stream_attribute = (IJL_VOID)GetProcAddress(hIJL, "_AIL_filter_stream_attribute@12");
	lpfn_AIL_filter_DLS_attribute = (IJL_VOID)GetProcAddress(hIJL, "_AIL_filter_DLS_attribute@12");
	lpfn_AIL_set_filter_preference = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_filter_preference@12");
	lpfn_AIL_set_filter_sample_preference = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_filter_sample_preference@12");
	lpfn_AIL_set_filter_stream_preference = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_filter_stream_preference@12");
	lpfn_AIL_set_filter_DLS_preference = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_filter_DLS_preference@12");
	lpfn_AIL_enumerate_3D_providers = (IJL_VOID)GetProcAddress(hIJL, "_AIL_enumerate_3D_providers@12");
	lpfn_AIL_open_3D_provider = (IJL_VOID)GetProcAddress(hIJL, "_AIL_open_3D_provider@4");
	lpfn_AIL_close_3D_provider = (IJL_VOID)GetProcAddress(hIJL, "_AIL_close_3D_provider@4");
	lpfn_AIL_enumerate_3D_provider_attributes = (IJL_VOID)GetProcAddress(hIJL, "_AIL_enumerate_3D_provider_attributes@12");
	lpfn_AIL_enumerate_3D_sample_attributes = (IJL_VOID)GetProcAddress(hIJL, "_AIL_enumerate_3D_sample_attributes@12");
	lpfn_AIL_3D_provider_attribute = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_provider_attribute@12");
	lpfn_AIL_3D_sample_attribute = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_attribute@12");
	lpfn_AIL_set_3D_provider_preference = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_provider_preference@12");
	lpfn_AIL_set_3D_sample_preference = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_preference@12");
	lpfn_AIL_allocate_3D_sample_handle = (IJL_VOID)GetProcAddress(hIJL, "_AIL_allocate_3D_sample_handle@4");
	lpfn_AIL_release_3D_sample_handle = (IJL_VOID)GetProcAddress(hIJL, "_AIL_release_3D_sample_handle@4");
	lpfn_AIL_start_3D_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_start_3D_sample@4");
	lpfn_AIL_stop_3D_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_stop_3D_sample@4");
	lpfn_AIL_resume_3D_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_resume_3D_sample@4");
	lpfn_AIL_end_3D_sample = (IJL_VOID)GetProcAddress(hIJL, "_AIL_end_3D_sample@4");
	lpfn_AIL_set_3D_sample_info = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_info@8");
	lpfn_AIL_set_3D_sample_file = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_file@8");
	lpfn_AIL_set_3D_sample_volume = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_volume@8");
	lpfn_AIL_set_3D_sample_playback_rate = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_playback_rate@8");
	lpfn_AIL_set_3D_sample_offset = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_offset@8");
	lpfn_AIL_set_3D_sample_loop_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_loop_count@8");
	lpfn_AIL_set_3D_sample_loop_block = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_loop_block@12");
	lpfn_AIL_set_3D_sample_obstruction = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_obstruction@8");
	lpfn_AIL_set_3D_sample_exclusion = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_exclusion@8");
	lpfn_AIL_set_3D_sample_occlusion = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_occlusion@8");
	lpfn_AIL_set_3D_sample_cone = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_cone@16");
	lpfn_AIL_set_3D_sample_effects_level = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_effects_level@8");
	lpfn_AIL_register_3D_EOS_callback = (IJL_VOID)GetProcAddress(hIJL, "_AIL_register_3D_EOS_callback@8");
	lpfn_AIL_3D_sample_obstruction = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_obstruction@4");
	lpfn_AIL_3D_sample_exclusion = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_exclusion@4");
	lpfn_AIL_3D_sample_occlusion = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_occlusion@4");
	lpfn_AIL_3D_sample_cone = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_cone@16");
	lpfn_AIL_3D_sample_effects_level = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_effects_level@4");
	lpfn_AIL_3D_sample_status = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_status@4");
	lpfn_AIL_3D_sample_volume = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_volume@4");
	lpfn_AIL_3D_sample_playback_rate = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_playback_rate@4");
	lpfn_AIL_3D_sample_offset = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_offset@4");
	lpfn_AIL_3D_sample_length = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_length@4");
	lpfn_AIL_3D_sample_loop_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_loop_count@4");
	lpfn_AIL_set_3D_sample_distances = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_sample_distances@12");
	lpfn_AIL_3D_sample_distances = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_sample_distances@12");
	lpfn_AIL_set_3D_user_data = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_user_data@12");
	lpfn_AIL_3D_user_data = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_user_data@8");
	lpfn_AIL_active_3D_sample_count = (IJL_VOID)GetProcAddress(hIJL, "_AIL_active_3D_sample_count@4");
	lpfn_AIL_3D_room_type = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_room_type@4");
	lpfn_AIL_set_3D_room_type = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_room_type@8");
	lpfn_AIL_3D_speaker_type = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_speaker_type@4");
	lpfn_AIL_set_3D_speaker_type = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_speaker_type@8");
	lpfn_AIL_3D_rolloff_factor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_rolloff_factor@4");
	lpfn_AIL_set_3D_rolloff_factor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_rolloff_factor@8");
	lpfn_AIL_3D_doppler_factor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_doppler_factor@4");
	lpfn_AIL_set_3D_doppler_factor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_doppler_factor@8");
	lpfn_AIL_3D_distance_factor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_distance_factor@4");
	lpfn_AIL_set_3D_distance_factor = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_distance_factor@8");
	lpfn_AIL_open_3D_listener = (IJL_VOID)GetProcAddress(hIJL, "_AIL_open_3D_listener@4");
	lpfn_AIL_close_3D_listener = (IJL_VOID)GetProcAddress(hIJL, "_AIL_close_3D_listener@4");
	lpfn_AIL_open_3D_object = (IJL_VOID)GetProcAddress(hIJL, "_AIL_open_3D_object@4");
	lpfn_AIL_close_3D_object = (IJL_VOID)GetProcAddress(hIJL, "_AIL_close_3D_object@4");
	lpfn_AIL_set_3D_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_position@16");
	lpfn_AIL_set_3D_velocity = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_velocity@20");
	lpfn_AIL_set_3D_velocity_vector = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_velocity_vector@16");
	lpfn_AIL_set_3D_orientation = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_3D_orientation@28");
	lpfn_AIL_3D_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_position@16");
	lpfn_AIL_3D_velocity = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_velocity@16");
	lpfn_AIL_3D_orientation = (IJL_VOID)GetProcAddress(hIJL, "_AIL_3D_orientation@28");
	lpfn_AIL_update_3D_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_update_3D_position@8");
	lpfn_AIL_auto_update_3D_position = (IJL_VOID)GetProcAddress(hIJL, "_AIL_auto_update_3D_position@8");
	lpfn_AIL_size_processed_digital_audio = (IJL_VOID)GetProcAddress(hIJL, "_AIL_size_processed_digital_audio@16");
	lpfn_AIL_process_digital_audio = (IJL_VOID)GetProcAddress(hIJL, "_AIL_process_digital_audio@24");
	lpfn_AIL_merge_DLS_with_XMI = (IJL_VOID)GetProcAddress(hIJL, "_AIL_merge_DLS_with_XMI@16");
	lpfn_AIL_compress_DLS = (IJL_VOID)GetProcAddress(hIJL, "_AIL_compress_DLS@20");
	lpfn_AIL_filter_DLS_with_XMI = (IJL_VOID)GetProcAddress(hIJL, "_AIL_filter_DLS_with_XMI@24");
	lpfn_AIL_compress_ASI = (IJL_VOID)GetProcAddress(hIJL, "_AIL_compress_ASI@20");
	lpfn_AIL_decompress_ASI = (IJL_VOID)GetProcAddress(hIJL, "_AIL_decompress_ASI@24");
	lpfn_AIL_request_EOB_ASI_reset = (IJL_VOID)GetProcAddress(hIJL, "_AIL_request_EOB_ASI_reset@8");
	lpfn_AIL_set_redist_directory = (IJL_VOID)GetProcAddress(hIJL, "_AIL_set_redist_directory@4");
	lpfn_MIX_RIB_MAIN = (IJL_VOID)GetProcAddress(hIJL, "_MIX_RIB_MAIN@8");
	lpfn_AIL_mem_use_malloc = (IJL_VOID)GetProcAddress(hIJL, "_AIL_mem_use_malloc@4");
	lpfn_AIL_mem_use_free = (IJL_VOID)GetProcAddress(hIJL, "_AIL_mem_use_free@4");
	lpfnAIL_sprintf = (IJL_VOID)GetProcAddress(hIJL, "AIL_sprintf");
	lpfnDLSMSSOpen = (IJL_VOID)GetProcAddress(hIJL, "DLSMSSOpen");
	lpfnDLSClose = (IJL_VOID)GetProcAddress(hIJL, "DLSClose");
	lpfnDLSLoadFile = (IJL_VOID)GetProcAddress(hIJL, "DLSLoadFile");
	lpfnDLSLoadMemFile = (IJL_VOID)GetProcAddress(hIJL, "DLSLoadMemFile");
	lpfnDLSGetInfo = (IJL_VOID)GetProcAddress(hIJL, "DLSGetInfo");
	lpfnDLSCompactMemory = (IJL_VOID)GetProcAddress(hIJL, "DLSCompactMemory");
	lpfnDLSUnloadAll = (IJL_VOID)GetProcAddress(hIJL, "DLSUnloadAll");
	lpfnDLSUnloadFile = (IJL_VOID)GetProcAddress(hIJL, "DLSUnloadFile");
	lpfnDLSSetAttribute = (IJL_VOID)GetProcAddress(hIJL, "DLSSetAttribute");
	lpfn_DLSMSSGetCPU = (IJL_VOID)GetProcAddress(hIJL, "_DLSMSSGetCPU@4");


	if (!lpfn_AIL_get_preference ||
		!lpfn_AIL_lock ||
		!lpfn_AIL_unlock ||
		!lpfn_AIL_lock_mutex ||
		!lpfn_AIL_unlock_mutex ||
		!lpfn_AIL_get_timer_highest_delay ||
		!lpfn_DllMain ||
		!lpfn_RIB_load_static_provider_library ||
		!lpfnRIB_alloc_provider_handle ||
		!lpfnRIB_free_provider_handle ||
		!lpfnRIB_load_provider_library ||
		!lpfnRIB_free_provider_library ||
		!lpfnRIB_register_interface ||
		!lpfnRIB_request_interface ||
		!lpfnRIB_request_interface_entry ||
		!lpfnRIB_unregister_interface ||
		!lpfnRIB_enumerate_interface ||
		!lpfn_RIB_enumerate_providers ||
		!lpfnRIB_type_string ||
		!lpfnRIB_find_file_provider ||
		!lpfn_RIB_find_files_provider ||
		!lpfn_RIB_find_file_dec_provider ||
		!lpfn_RIB_find_provider ||
		!lpfn_RIB_load_application_providers ||
		!lpfn_RIB_set_provider_user_data ||
		!lpfn_RIB_provider_user_data ||
		!lpfn_RIB_set_provider_system_data ||
		!lpfn_RIB_provider_system_data ||
		!lpfnRIB_error ||
		!lpfn_AIL_set_file_async_callbacks ||
		!lpfn_AIL_set_file_callbacks ||
		!lpfn_AIL_list_DLS ||
		!lpfn_AIL_list_MIDI ||
		!lpfnstream_background ||
		!lpfn_AIL_ms_count ||
		!lpfn_AIL_us_count ||
		!lpfn_AIL_MMX_available ||
		!lpfnAIL_debug_printf ||
		!lpfn_AIL_startup ||
		!lpfn_AIL_shutdown ||
		!lpfn_AIL_HWND ||
		!lpfn_AIL_mem_alloc_lock ||
		!lpfn_AIL_mem_free_lock ||
		!lpfn_AIL_set_preference ||
		!lpfn_AIL_last_error ||
		!lpfn_AIL_set_error ||
		!lpfn_AIL_delay ||
		!lpfn_AIL_background ||
		!lpfn_AIL_register_timer ||
		!lpfn_AIL_set_timer_user ||
		!lpfn_AIL_set_timer_period ||
		!lpfn_AIL_set_timer_frequency ||
		!lpfn_AIL_set_timer_divisor ||
		!lpfn_AIL_start_timer ||
		!lpfn_AIL_start_all_timers ||
		!lpfn_AIL_stop_timer ||
		!lpfn_AIL_stop_all_timers ||
		!lpfn_AIL_release_timer_handle ||
		!lpfn_AIL_release_all_timers ||
		!lpfn_AIL_open_digital_driver ||
		!lpfn_AIL_close_digital_driver ||
		!lpfn_AIL_waveOutOpen ||
		!lpfn_AIL_waveOutClose ||
		!lpfn_AIL_digital_handle_release ||
		!lpfn_AIL_digital_handle_reacquire ||
		!lpfn_AIL_open_input ||
		!lpfn_AIL_close_input ||
		!lpfn_AIL_get_input_info ||
		!lpfn_AIL_set_input_state ||
		!lpfn_AIL_digital_CPU_percent ||
		!lpfn_AIL_digital_latency ||
		!lpfn_AIL_allocate_sample_handle ||
		!lpfn_AIL_allocate_file_sample ||
		!lpfn_AIL_release_sample_handle ||
		!lpfn_AIL_init_sample ||
		!lpfn_AIL_set_sample_file ||
		!lpfn_AIL_set_named_sample_file ||
		!lpfn_AIL_set_sample_processor ||
		!lpfn_AIL_set_stream_processor ||
		!lpfn_AIL_set_DLS_processor ||
		!lpfn_AIL_set_digital_driver_processor ||
		!lpfn_AIL_set_sample_address ||
		!lpfn_AIL_set_sample_type ||
		!lpfn_AIL_set_sample_adpcm_block_size ||
		!lpfn_AIL_start_sample ||
		!lpfn_AIL_stop_sample ||
		!lpfn_AIL_resume_sample ||
		!lpfn_AIL_end_sample ||
		!lpfn_AIL_set_sample_playback_rate ||
		!lpfn_AIL_set_sample_volume_pan ||
		!lpfn_AIL_set_sample_volume_levels ||
		!lpfn_AIL_set_sample_reverb_levels ||
		!lpfn_AIL_set_sample_low_pass_cut_off ||
		!lpfn_AIL_set_sample_loop_count ||
		!lpfn_AIL_set_sample_loop_block ||
		!lpfn_AIL_sample_status ||
		!lpfn_AIL_sample_playback_rate ||
		!lpfn_AIL_sample_volume_pan ||
		!lpfn_AIL_sample_volume_levels ||
		!lpfn_AIL_sample_reverb_levels ||
		!lpfn_AIL_sample_low_pass_cut_off ||
		!lpfn_AIL_sample_loop_count ||
		!lpfn_AIL_set_digital_master_volume_level ||
		!lpfn_AIL_digital_master_volume_level ||
		!lpfn_AIL_set_digital_master_reverb_levels ||
		!lpfn_AIL_set_digital_master_room_type ||
		!lpfn_AIL_digital_master_reverb_levels ||
		!lpfn_AIL_set_digital_master_reverb ||
		!lpfn_AIL_digital_master_reverb ||
		!lpfn_AIL_minimum_sample_buffer_size ||
		!lpfn_AIL_sample_buffer_ready ||
		!lpfn_AIL_load_sample_buffer ||
		!lpfn_AIL_sample_buffer_info ||
		!lpfn_AIL_sample_granularity ||
		!lpfn_AIL_set_sample_position ||
		!lpfn_AIL_sample_position ||
		!lpfn_AIL_register_SOB_callback ||
		!lpfn_AIL_register_EOB_callback ||
		!lpfn_AIL_register_EOS_callback ||
		!lpfn_AIL_register_EOF_callback ||
		!lpfn_AIL_set_sample_user_data ||
		!lpfn_AIL_sample_user_data ||
		!lpfn_AIL_active_sample_count ||
		!lpfn_AIL_digital_configuration ||
		!lpfn_AIL_get_DirectSound_info ||
		!lpfn_AIL_set_DirectSound_HWND ||
		!lpfn_AIL_open_XMIDI_driver ||
		!lpfn_AIL_close_XMIDI_driver ||
		!lpfn_AIL_midiOutOpen ||
		!lpfn_AIL_midiOutClose ||
		!lpfn_AIL_MIDI_handle_release ||
		!lpfn_AIL_MIDI_handle_reacquire ||
		!lpfn_AIL_allocate_sequence_handle ||
		!lpfn_AIL_release_sequence_handle ||
		!lpfn_AIL_init_sequence ||
		!lpfn_AIL_start_sequence ||
		!lpfn_AIL_stop_sequence ||
		!lpfn_AIL_resume_sequence ||
		!lpfn_AIL_end_sequence ||
		!lpfn_AIL_set_sequence_tempo ||
		!lpfn_AIL_set_sequence_volume ||
		!lpfn_AIL_set_sequence_loop_count ||
		!lpfn_AIL_sequence_status ||
		!lpfn_AIL_sequence_tempo ||
		!lpfn_AIL_sequence_volume ||
		!lpfn_AIL_sequence_loop_count ||
		!lpfn_AIL_set_XMIDI_master_volume ||
		!lpfn_AIL_XMIDI_master_volume ||
		!lpfn_AIL_active_sequence_count ||
		!lpfn_AIL_controller_value ||
		!lpfn_AIL_channel_notes ||
		!lpfn_AIL_sequence_position ||
		!lpfn_AIL_branch_index ||
		!lpfn_AIL_register_prefix_callback ||
		!lpfn_AIL_register_trigger_callback ||
		!lpfn_AIL_register_sequence_callback ||
		!lpfn_AIL_register_beat_callback ||
		!lpfn_AIL_register_event_callback ||
		!lpfn_AIL_register_timbre_callback ||
		!lpfn_AIL_set_sequence_user_data ||
		!lpfn_AIL_sequence_user_data ||
		!lpfn_AIL_register_ICA_array ||
		!lpfn_AIL_lock_channel ||
		!lpfn_AIL_release_channel ||
		!lpfn_AIL_map_sequence_channel ||
		!lpfn_AIL_true_sequence_channel ||
		!lpfn_AIL_send_channel_voice_message ||
		!lpfn_AIL_send_sysex_message ||
		!lpfn_AIL_create_wave_synthesizer ||
		!lpfn_AIL_destroy_wave_synthesizer ||
		!lpfn_AIL_file_error ||
		!lpfn_AIL_file_size ||
		!lpfn_AIL_file_read ||
		!lpfn_AIL_file_write ||
		!lpfn_AIL_WAV_file_write ||
		!lpfn_AIL_serve ||
		!lpfn_AIL_redbook_open ||
		!lpfn_AIL_redbook_open_drive ||
		!lpfn_AIL_redbook_close ||
		!lpfn_AIL_redbook_eject ||
		!lpfn_AIL_redbook_retract ||
		!lpfn_AIL_redbook_status ||
		!lpfn_AIL_redbook_tracks ||
		!lpfn_AIL_redbook_track ||
		!lpfn_AIL_redbook_track_info ||
		!lpfn_AIL_redbook_id ||
		!lpfn_AIL_redbook_position ||
		!lpfn_AIL_redbook_play ||
		!lpfn_AIL_redbook_stop ||
		!lpfn_AIL_redbook_pause ||
		!lpfn_AIL_redbook_resume ||
		!lpfn_AIL_redbook_volume_level ||
		!lpfn_AIL_redbook_set_volume_level ||
		!lpfn_AIL_quick_startup ||
		!lpfn_AIL_quick_shutdown ||
		!lpfn_AIL_quick_handles ||
		!lpfn_AIL_quick_load ||
		!lpfn_AIL_quick_load_mem ||
		!lpfn_AIL_quick_copy ||
		!lpfn_AIL_quick_unload ||
		!lpfn_AIL_quick_play ||
		!lpfn_AIL_quick_halt ||
		!lpfn_AIL_quick_status ||
		!lpfn_AIL_quick_load_and_play ||
		!lpfn_AIL_quick_set_speed ||
		!lpfn_AIL_quick_set_volume ||
		!lpfn_AIL_quick_set_reverb_levels ||
		!lpfn_AIL_quick_set_low_pass_cut_off ||
		!lpfn_AIL_open_stream ||
		!lpfn_AIL_close_stream ||
		!lpfn_AIL_service_stream ||
		!lpfn_AIL_start_stream ||
		!lpfn_AIL_pause_stream ||
		!lpfn_AIL_set_stream_volume_pan ||
		!lpfn_AIL_set_stream_volume_levels ||
		!lpfn_AIL_set_stream_reverb_levels ||
		!lpfn_AIL_set_stream_low_pass_cut_off ||
		!lpfn_AIL_stream_volume_pan ||
		!lpfn_AIL_stream_volume_levels ||
		!lpfn_AIL_stream_reverb_levels ||
		!lpfn_AIL_stream_low_pass_cut_off ||
		!lpfn_AIL_set_stream_playback_rate ||
		!lpfn_AIL_stream_playback_rate ||
		!lpfn_AIL_stream_loop_count ||
		!lpfn_AIL_set_stream_loop_block ||
		!lpfn_AIL_set_stream_loop_count ||
		!lpfn_AIL_stream_status ||
		!lpfn_AIL_set_stream_position ||
		!lpfn_AIL_stream_position ||
		!lpfn_AIL_stream_info ||
		!lpfn_AIL_register_stream_callback ||
		!lpfn_AIL_auto_service_stream ||
		!lpfn_AIL_set_stream_user_data ||
		!lpfn_AIL_stream_user_data ||
		!lpfn_AIL_DLS_open ||
		!lpfn_AIL_DLS_close ||
		!lpfn_AIL_DLS_load_file ||
		!lpfn_AIL_DLS_load_memory ||
		!lpfn_AIL_DLS_unload ||
		!lpfn_AIL_DLS_compact ||
		!lpfn_AIL_DLS_set_reverb_levels ||
		!lpfn_AIL_DLS_get_reverb_levels ||
		!lpfn_AIL_DLS_get_info ||
		!lpfn_AIL_set_sequence_ms_position ||
		!lpfn_AIL_sequence_ms_position ||
		!lpfn_AIL_sample_ms_position ||
		!lpfn_AIL_set_sample_ms_position ||
		!lpfn_AIL_stream_ms_position ||
		!lpfn_AIL_set_stream_ms_position ||
		!lpfn_AIL_quick_set_ms_position ||
		!lpfn_AIL_quick_ms_position ||
		!lpfn_AIL_quick_ms_length ||
		!lpfn_AIL_quick_type ||
		!lpfn_AIL_MIDI_to_XMI ||
		!lpfn_AIL_compress_ADPCM ||
		!lpfn_AIL_decompress_ADPCM ||
		!lpfn_AIL_WAV_info ||
		!lpfn_AIL_file_type ||
		!lpfn_AIL_find_DLS ||
		!lpfn_AIL_extract_DLS ||
		!lpfn_AIL_primary_digital_driver ||
		!lpfn_AIL_enumerate_filters ||
		!lpfn_AIL_open_filter ||
		!lpfn_AIL_close_filter ||
		!lpfn_AIL_enumerate_filter_attributes ||
		!lpfn_AIL_enumerate_filter_sample_attribute ||
		!lpfn_AIL_filter_attribute ||
		!lpfn_AIL_filter_sample_attribute ||
		!lpfn_AIL_filter_stream_attribute ||
		!lpfn_AIL_filter_DLS_attribute ||
		!lpfn_AIL_set_filter_preference ||
		!lpfn_AIL_set_filter_sample_preference ||
		!lpfn_AIL_set_filter_stream_preference ||
		!lpfn_AIL_set_filter_DLS_preference ||
		!lpfn_AIL_enumerate_3D_providers ||
		!lpfn_AIL_open_3D_provider ||
		!lpfn_AIL_close_3D_provider ||
		!lpfn_AIL_enumerate_3D_provider_attributes ||
		!lpfn_AIL_enumerate_3D_sample_attributes ||
		!lpfn_AIL_3D_provider_attribute ||
		!lpfn_AIL_3D_sample_attribute ||
		!lpfn_AIL_set_3D_provider_preference ||
		!lpfn_AIL_set_3D_sample_preference ||
		!lpfn_AIL_allocate_3D_sample_handle ||
		!lpfn_AIL_release_3D_sample_handle ||
		!lpfn_AIL_start_3D_sample ||
		!lpfn_AIL_stop_3D_sample ||
		!lpfn_AIL_resume_3D_sample ||
		!lpfn_AIL_end_3D_sample ||
		!lpfn_AIL_set_3D_sample_info ||
		!lpfn_AIL_set_3D_sample_file ||
		!lpfn_AIL_set_3D_sample_volume ||
		!lpfn_AIL_set_3D_sample_playback_rate ||
		!lpfn_AIL_set_3D_sample_offset ||
		!lpfn_AIL_set_3D_sample_loop_count ||
		!lpfn_AIL_set_3D_sample_loop_block ||
		!lpfn_AIL_set_3D_sample_obstruction ||
		!lpfn_AIL_set_3D_sample_exclusion ||
		!lpfn_AIL_set_3D_sample_occlusion ||
		!lpfn_AIL_set_3D_sample_cone ||
		!lpfn_AIL_set_3D_sample_effects_level ||
		!lpfn_AIL_register_3D_EOS_callback ||
		!lpfn_AIL_3D_sample_obstruction ||
		!lpfn_AIL_3D_sample_exclusion ||
		!lpfn_AIL_3D_sample_occlusion ||
		!lpfn_AIL_3D_sample_cone ||
		!lpfn_AIL_3D_sample_effects_level ||
		!lpfn_AIL_3D_sample_status ||
		!lpfn_AIL_3D_sample_volume ||
		!lpfn_AIL_3D_sample_playback_rate ||
		!lpfn_AIL_3D_sample_offset ||
		!lpfn_AIL_3D_sample_length ||
		!lpfn_AIL_3D_sample_loop_count ||
		!lpfn_AIL_set_3D_sample_distances ||
		!lpfn_AIL_3D_sample_distances ||
		!lpfn_AIL_set_3D_user_data ||
		!lpfn_AIL_3D_user_data ||
		!lpfn_AIL_active_3D_sample_count ||
		!lpfn_AIL_3D_room_type ||
		!lpfn_AIL_set_3D_room_type ||
		!lpfn_AIL_3D_speaker_type ||
		!lpfn_AIL_set_3D_speaker_type ||
		!lpfn_AIL_3D_rolloff_factor ||
		!lpfn_AIL_set_3D_rolloff_factor ||
		!lpfn_AIL_3D_doppler_factor ||
		!lpfn_AIL_set_3D_doppler_factor ||
		!lpfn_AIL_3D_distance_factor ||
		!lpfn_AIL_set_3D_distance_factor ||
		!lpfn_AIL_open_3D_listener ||
		!lpfn_AIL_close_3D_listener ||
		!lpfn_AIL_open_3D_object ||
		!lpfn_AIL_close_3D_object ||
		!lpfn_AIL_set_3D_position ||
		!lpfn_AIL_set_3D_velocity ||
		!lpfn_AIL_set_3D_velocity_vector ||
		!lpfn_AIL_set_3D_orientation ||
		!lpfn_AIL_3D_position ||
		!lpfn_AIL_3D_velocity ||
		!lpfn_AIL_3D_orientation ||
		!lpfn_AIL_update_3D_position ||
		!lpfn_AIL_auto_update_3D_position ||
		!lpfn_AIL_size_processed_digital_audio ||
		!lpfn_AIL_process_digital_audio ||
		!lpfn_AIL_merge_DLS_with_XMI ||
		!lpfn_AIL_compress_DLS ||
		!lpfn_AIL_filter_DLS_with_XMI ||
		!lpfn_AIL_compress_ASI ||
		!lpfn_AIL_decompress_ASI ||
		!lpfn_AIL_request_EOB_ASI_reset ||
		!lpfn_AIL_set_redist_directory ||
		!lpfn_MIX_RIB_MAIN ||
		!lpfn_AIL_mem_use_malloc ||
		!lpfn_AIL_mem_use_free ||
		!lpfnAIL_sprintf ||
		!lpfnDLSMSSOpen ||
		!lpfnDLSClose ||
		!lpfnDLSLoadFile ||
		!lpfnDLSLoadMemFile ||
		!lpfnDLSGetInfo ||
		!lpfnDLSCompactMemory ||
		!lpfnDLSUnloadAll ||
		!lpfnDLSUnloadFile ||
		!lpfnDLSSetAttribute ||
		!lpfn_DLSMSSGetCPU)
	{
		WriteLog("-- Mss32.dll Export Table Log Start --\n");
		WriteLog("_AIL_get_preference                   %x\n", lpfn_AIL_get_preference);
		WriteLog("_AIL_lock                             %x\n", lpfn_AIL_lock);
		WriteLog("_AIL_unlock                           %x\n", lpfn_AIL_unlock);
		WriteLog("_AIL_lock_mutex                       %x\n", lpfn_AIL_lock_mutex);
		WriteLog("_AIL_unlock_mutex                     %x\n", lpfn_AIL_unlock_mutex);
		WriteLog("_AIL_get_timer_highest_delay          %x\n", lpfn_AIL_get_timer_highest_delay);
		WriteLog("_DllMain                              %x\n", lpfn_DllMain);
		WriteLog("_RIB_load_static_provider_library     %x\n", lpfn_RIB_load_static_provider_library);
		WriteLog("RIB_alloc_provider_handle             %x\n", lpfnRIB_alloc_provider_handle);
		WriteLog("RIB_free_provider_handle              %x\n", lpfnRIB_free_provider_handle);
		WriteLog("RIB_load_provider_library             %x\n", lpfnRIB_load_provider_library);
		WriteLog("RIB_free_provider_library             %x\n", lpfnRIB_free_provider_library);
		WriteLog("RIB_register_interface                %x\n", lpfnRIB_register_interface);
		WriteLog("RIB_request_interface                 %x\n", lpfnRIB_request_interface);
		WriteLog("RIB_request_interface_entry           %x\n", lpfnRIB_request_interface_entry);
		WriteLog("RIB_unregister_interface              %x\n", lpfnRIB_unregister_interface);
		WriteLog("RIB_enumerate_interface               %x\n", lpfnRIB_enumerate_interface);
		WriteLog("_RIB_enumerate_providers              %x\n", lpfn_RIB_enumerate_providers);
		WriteLog("RIB_type_string                       %x\n", lpfnRIB_type_string);
		WriteLog("RIB_find_file_provider                %x\n", lpfnRIB_find_file_provider);
		WriteLog("_RIB_find_files_provider              %x\n", lpfn_RIB_find_files_provider);
		WriteLog("_RIB_find_file_dec_provider           %x\n", lpfn_RIB_find_file_dec_provider);
		WriteLog("_RIB_find_provider                    %x\n", lpfn_RIB_find_provider);
		WriteLog("_RIB_load_application_providers       %x\n", lpfn_RIB_load_application_providers);
		WriteLog("_RIB_set_provider_user_data           %x\n", lpfn_RIB_set_provider_user_data);
		WriteLog("_RIB_provider_user_data               %x\n", lpfn_RIB_provider_user_data);
		WriteLog("_RIB_set_provider_system_data         %x\n", lpfn_RIB_set_provider_system_data);
		WriteLog("_RIB_provider_system_data             %x\n", lpfn_RIB_provider_system_data);
		WriteLog("RIB_error                             %x\n", lpfnRIB_error);
		WriteLog("_AIL_set_file_async_callbacks         %x\n", lpfn_AIL_set_file_async_callbacks);
		WriteLog("_AIL_set_file_callbacks               %x\n", lpfn_AIL_set_file_callbacks);
		WriteLog("_AIL_list_DLS                         %x\n", lpfn_AIL_list_DLS);
		WriteLog("_AIL_list_MIDI                        %x\n", lpfn_AIL_list_MIDI);
		WriteLog("stream_background                     %x\n", lpfnstream_background);
		WriteLog("_AIL_ms_count                         %x\n", lpfn_AIL_ms_count);
		WriteLog("_AIL_us_count                         %x\n", lpfn_AIL_us_count);
		WriteLog("_AIL_MMX_available                    %x\n", lpfn_AIL_MMX_available);
		WriteLog("AIL_debug_printf                      %x\n", lpfnAIL_debug_printf);
		WriteLog("_AIL_startup                          %x\n", lpfn_AIL_startup);
		WriteLog("_AIL_shutdown                         %x\n", lpfn_AIL_shutdown);
		WriteLog("_AIL_HWND                             %x\n", lpfn_AIL_HWND);
		WriteLog("_AIL_mem_alloc_lock                   %x\n", lpfn_AIL_mem_alloc_lock);
		WriteLog("_AIL_mem_free_lock                    %x\n", lpfn_AIL_mem_free_lock);
		WriteLog("_AIL_set_preference                   %x\n", lpfn_AIL_set_preference);
		WriteLog("_AIL_last_error                       %x\n", lpfn_AIL_last_error);
		WriteLog("_AIL_set_error                        %x\n", lpfn_AIL_set_error);
		WriteLog("_AIL_delay                            %x\n", lpfn_AIL_delay);
		WriteLog("_AIL_background                       %x\n", lpfn_AIL_background);
		WriteLog("_AIL_register_timer                   %x\n", lpfn_AIL_register_timer);
		WriteLog("_AIL_set_timer_user                   %x\n", lpfn_AIL_set_timer_user);
		WriteLog("_AIL_set_timer_period                 %x\n", lpfn_AIL_set_timer_period);
		WriteLog("_AIL_set_timer_frequency              %x\n", lpfn_AIL_set_timer_frequency);
		WriteLog("_AIL_set_timer_divisor                %x\n", lpfn_AIL_set_timer_divisor);
		WriteLog("_AIL_start_timer                      %x\n", lpfn_AIL_start_timer);
		WriteLog("_AIL_start_all_timers                 %x\n", lpfn_AIL_start_all_timers);
		WriteLog("_AIL_stop_timer                       %x\n", lpfn_AIL_stop_timer);
		WriteLog("_AIL_stop_all_timers                  %x\n", lpfn_AIL_stop_all_timers);
		WriteLog("_AIL_release_timer_handle             %x\n", lpfn_AIL_release_timer_handle);
		WriteLog("_AIL_release_all_timers               %x\n", lpfn_AIL_release_all_timers);
		WriteLog("_AIL_open_digital_driver              %x\n", lpfn_AIL_open_digital_driver);
		WriteLog("_AIL_close_digital_driver             %x\n", lpfn_AIL_close_digital_driver);
		WriteLog("_AIL_waveOutOpen                      %x\n", lpfn_AIL_waveOutOpen);
		WriteLog("_AIL_waveOutClose                     %x\n", lpfn_AIL_waveOutClose);
		WriteLog("_AIL_digital_handle_release           %x\n", lpfn_AIL_digital_handle_release);
		WriteLog("_AIL_digital_handle_reacquire         %x\n", lpfn_AIL_digital_handle_reacquire);
		WriteLog("_AIL_open_input                       %x\n", lpfn_AIL_open_input);
		WriteLog("_AIL_close_input                      %x\n", lpfn_AIL_close_input);
		WriteLog("_AIL_get_input_info                   %x\n", lpfn_AIL_get_input_info);
		WriteLog("_AIL_set_input_state                  %x\n", lpfn_AIL_set_input_state);
		WriteLog("_AIL_digital_CPU_percent              %x\n", lpfn_AIL_digital_CPU_percent);
		WriteLog("_AIL_digital_latency                  %x\n", lpfn_AIL_digital_latency);
		WriteLog("_AIL_allocate_sample_handle           %x\n", lpfn_AIL_allocate_sample_handle);
		WriteLog("_AIL_allocate_file_sample             %x\n", lpfn_AIL_allocate_file_sample);
		WriteLog("_AIL_release_sample_handle            %x\n", lpfn_AIL_release_sample_handle);
		WriteLog("_AIL_init_sample                      %x\n", lpfn_AIL_init_sample);
		WriteLog("_AIL_set_sample_file                  %x\n", lpfn_AIL_set_sample_file);
		WriteLog("_AIL_set_named_sample_file            %x\n", lpfn_AIL_set_named_sample_file);
		WriteLog("_AIL_set_sample_processor             %x\n", lpfn_AIL_set_sample_processor);
		WriteLog("_AIL_set_stream_processor             %x\n", lpfn_AIL_set_stream_processor);
		WriteLog("_AIL_set_DLS_processor                %x\n", lpfn_AIL_set_DLS_processor);
		WriteLog("_AIL_set_digital_driver_processor     %x\n", lpfn_AIL_set_digital_driver_processor);
		WriteLog("_AIL_set_sample_address               %x\n", lpfn_AIL_set_sample_address);
		WriteLog("_AIL_set_sample_type                  %x\n", lpfn_AIL_set_sample_type);
		WriteLog("_AIL_set_sample_adpcm_block_size      %x\n", lpfn_AIL_set_sample_adpcm_block_size);
		WriteLog("_AIL_start_sample                     %x\n", lpfn_AIL_start_sample);
		WriteLog("_AIL_stop_sample                      %x\n", lpfn_AIL_stop_sample);
		WriteLog("_AIL_resume_sample                    %x\n", lpfn_AIL_resume_sample);
		WriteLog("_AIL_end_sample                       %x\n", lpfn_AIL_end_sample);
		WriteLog("_AIL_set_sample_playback_rate         %x\n", lpfn_AIL_set_sample_playback_rate);
		WriteLog("_AIL_set_sample_volume_pan            %x\n", lpfn_AIL_set_sample_volume_pan);
		WriteLog("_AIL_set_sample_volume_levels         %x\n", lpfn_AIL_set_sample_volume_levels);
		WriteLog("_AIL_set_sample_reverb_levels         %x\n", lpfn_AIL_set_sample_reverb_levels);
		WriteLog("_AIL_set_sample_low_pass_cut_off      %x\n", lpfn_AIL_set_sample_low_pass_cut_off);
		WriteLog("_AIL_set_sample_loop_count            %x\n", lpfn_AIL_set_sample_loop_count);
		WriteLog("_AIL_set_sample_loop_block            %x\n", lpfn_AIL_set_sample_loop_block);
		WriteLog("_AIL_sample_status                    %x\n", lpfn_AIL_sample_status);
		WriteLog("_AIL_sample_playback_rate             %x\n", lpfn_AIL_sample_playback_rate);
		WriteLog("_AIL_sample_volume_pan                %x\n", lpfn_AIL_sample_volume_pan);
		WriteLog("_AIL_sample_volume_levels             %x\n", lpfn_AIL_sample_volume_levels);
		WriteLog("_AIL_sample_reverb_levels             %x\n", lpfn_AIL_sample_reverb_levels);
		WriteLog("_AIL_sample_low_pass_cut_off          %x\n", lpfn_AIL_sample_low_pass_cut_off);
		WriteLog("_AIL_sample_loop_count                %x\n", lpfn_AIL_sample_loop_count);
		WriteLog("_AIL_set_digital_master_volume_level  %x\n", lpfn_AIL_set_digital_master_volume_level);
		WriteLog("_AIL_digital_master_volume_level      %x\n", lpfn_AIL_digital_master_volume_level);
		WriteLog("_AIL_set_digital_master_reverb_levels %x\n", lpfn_AIL_set_digital_master_reverb_levels);
		WriteLog("_AIL_set_digital_master_room_type     %x\n", lpfn_AIL_set_digital_master_room_type);
		WriteLog("_AIL_digital_master_reverb_levels     %x\n", lpfn_AIL_digital_master_reverb_levels);
		WriteLog("_AIL_set_digital_master_reverb        %x\n", lpfn_AIL_set_digital_master_reverb);
		WriteLog("_AIL_digital_master_reverb            %x\n", lpfn_AIL_digital_master_reverb);
		WriteLog("_AIL_minimum_sample_buffer_size       %x\n", lpfn_AIL_minimum_sample_buffer_size);
		WriteLog("_AIL_sample_buffer_ready              %x\n", lpfn_AIL_sample_buffer_ready);
		WriteLog("_AIL_load_sample_buffer               %x\n", lpfn_AIL_load_sample_buffer);
		WriteLog("_AIL_sample_buffer_info               %x\n", lpfn_AIL_sample_buffer_info);
		WriteLog("_AIL_sample_granularity               %x\n", lpfn_AIL_sample_granularity);
		WriteLog("_AIL_set_sample_position              %x\n", lpfn_AIL_set_sample_position);
		WriteLog("_AIL_sample_position                  %x\n", lpfn_AIL_sample_position);
		WriteLog("_AIL_register_SOB_callback            %x\n", lpfn_AIL_register_SOB_callback);
		WriteLog("_AIL_register_EOB_callback            %x\n", lpfn_AIL_register_EOB_callback);
		WriteLog("_AIL_register_EOS_callback            %x\n", lpfn_AIL_register_EOS_callback);
		WriteLog("_AIL_register_EOF_callback            %x\n", lpfn_AIL_register_EOF_callback);
		WriteLog("_AIL_set_sample_user_data             %x\n", lpfn_AIL_set_sample_user_data);
		WriteLog("_AIL_sample_user_data                 %x\n", lpfn_AIL_sample_user_data);
		WriteLog("_AIL_active_sample_count              %x\n", lpfn_AIL_active_sample_count);
		WriteLog("_AIL_digital_configuration            %x\n", lpfn_AIL_digital_configuration);
		WriteLog("_AIL_get_DirectSound_info             %x\n", lpfn_AIL_get_DirectSound_info);
		WriteLog("_AIL_set_DirectSound_HWND             %x\n", lpfn_AIL_set_DirectSound_HWND);
		WriteLog("_AIL_open_XMIDI_driver                %x\n", lpfn_AIL_open_XMIDI_driver);
		WriteLog("_AIL_close_XMIDI_driver               %x\n", lpfn_AIL_close_XMIDI_driver);
		WriteLog("_AIL_midiOutOpen                      %x\n", lpfn_AIL_midiOutOpen);
		WriteLog("_AIL_midiOutClose                     %x\n", lpfn_AIL_midiOutClose);
		WriteLog("_AIL_MIDI_handle_release              %x\n", lpfn_AIL_MIDI_handle_release);
		WriteLog("_AIL_MIDI_handle_reacquire            %x\n", lpfn_AIL_MIDI_handle_reacquire);
		WriteLog("_AIL_allocate_sequence_handle         %x\n", lpfn_AIL_allocate_sequence_handle);
		WriteLog("_AIL_release_sequence_handle          %x\n", lpfn_AIL_release_sequence_handle);
		WriteLog("_AIL_init_sequence                    %x\n", lpfn_AIL_init_sequence);
		WriteLog("_AIL_start_sequence                   %x\n", lpfn_AIL_start_sequence);
		WriteLog("_AIL_stop_sequence                    %x\n", lpfn_AIL_stop_sequence);
		WriteLog("_AIL_resume_sequence                  %x\n", lpfn_AIL_resume_sequence);
		WriteLog("_AIL_end_sequence                     %x\n", lpfn_AIL_end_sequence);
		WriteLog("_AIL_set_sequence_tempo               %x\n", lpfn_AIL_set_sequence_tempo);
		WriteLog("_AIL_set_sequence_volume              %x\n", lpfn_AIL_set_sequence_volume);
		WriteLog("_AIL_set_sequence_loop_count          %x\n", lpfn_AIL_set_sequence_loop_count);
		WriteLog("_AIL_sequence_status                  %x\n", lpfn_AIL_sequence_status);
		WriteLog("_AIL_sequence_tempo                   %x\n", lpfn_AIL_sequence_tempo);
		WriteLog("_AIL_sequence_volume                  %x\n", lpfn_AIL_sequence_volume);
		WriteLog("_AIL_sequence_loop_count              %x\n", lpfn_AIL_sequence_loop_count);
		WriteLog("_AIL_set_XMIDI_master_volume          %x\n", lpfn_AIL_set_XMIDI_master_volume);
		WriteLog("_AIL_XMIDI_master_volume              %x\n", lpfn_AIL_XMIDI_master_volume);
		WriteLog("_AIL_active_sequence_count            %x\n", lpfn_AIL_active_sequence_count);
		WriteLog("_AIL_controller_value                 %x\n", lpfn_AIL_controller_value);
		WriteLog("_AIL_channel_notes                    %x\n", lpfn_AIL_channel_notes);
		WriteLog("_AIL_sequence_position                %x\n", lpfn_AIL_sequence_position);
		WriteLog("_AIL_branch_index                     %x\n", lpfn_AIL_branch_index);
		WriteLog("_AIL_register_prefix_callback         %x\n", lpfn_AIL_register_prefix_callback);
		WriteLog("_AIL_register_trigger_callback        %x\n", lpfn_AIL_register_trigger_callback);
		WriteLog("_AIL_register_sequence_callback       %x\n", lpfn_AIL_register_sequence_callback);
		WriteLog("_AIL_register_beat_callback           %x\n", lpfn_AIL_register_beat_callback);
		WriteLog("_AIL_register_event_callback          %x\n", lpfn_AIL_register_event_callback);
		WriteLog("_AIL_register_timbre_callback         %x\n", lpfn_AIL_register_timbre_callback);
		WriteLog("_AIL_set_sequence_user_data           %x\n", lpfn_AIL_set_sequence_user_data);
		WriteLog("_AIL_sequence_user_data               %x\n", lpfn_AIL_sequence_user_data);
		WriteLog("_AIL_register_ICA_array               %x\n", lpfn_AIL_register_ICA_array);
		WriteLog("_AIL_lock_channel                     %x\n", lpfn_AIL_lock_channel);
		WriteLog("_AIL_release_channel                  %x\n", lpfn_AIL_release_channel);
		WriteLog("_AIL_map_sequence_channel             %x\n", lpfn_AIL_map_sequence_channel);
		WriteLog("_AIL_true_sequence_channel            %x\n", lpfn_AIL_true_sequence_channel);
		WriteLog("_AIL_send_channel_voice_message       %x\n", lpfn_AIL_send_channel_voice_message);
		WriteLog("_AIL_send_sysex_message               %x\n", lpfn_AIL_send_sysex_message);
		WriteLog("_AIL_create_wave_synthesizer          %x\n", lpfn_AIL_create_wave_synthesizer);
		WriteLog("_AIL_destroy_wave_synthesizer         %x\n", lpfn_AIL_destroy_wave_synthesizer);
		WriteLog("_AIL_file_error                       %x\n", lpfn_AIL_file_error);
		WriteLog("_AIL_file_size                        %x\n", lpfn_AIL_file_size);
		WriteLog("_AIL_file_read                        %x\n", lpfn_AIL_file_read);
		WriteLog("_AIL_file_write                       %x\n", lpfn_AIL_file_write);
		WriteLog("_AIL_WAV_file_write                   %x\n", lpfn_AIL_WAV_file_write);
		WriteLog("_AIL_serve                            %x\n", lpfn_AIL_serve);
		WriteLog("_AIL_redbook_open                     %x\n", lpfn_AIL_redbook_open);
		WriteLog("_AIL_redbook_open_drive               %x\n", lpfn_AIL_redbook_open_drive);
		WriteLog("_AIL_redbook_close                    %x\n", lpfn_AIL_redbook_close);
		WriteLog("_AIL_redbook_eject                    %x\n", lpfn_AIL_redbook_eject);
		WriteLog("_AIL_redbook_retract                  %x\n", lpfn_AIL_redbook_retract);
		WriteLog("_AIL_redbook_status                   %x\n", lpfn_AIL_redbook_status);
		WriteLog("_AIL_redbook_tracks                   %x\n", lpfn_AIL_redbook_tracks);
		WriteLog("_AIL_redbook_track                    %x\n", lpfn_AIL_redbook_track);
		WriteLog("_AIL_redbook_track_info               %x\n", lpfn_AIL_redbook_track_info);
		WriteLog("_AIL_redbook_id                       %x\n", lpfn_AIL_redbook_id);
		WriteLog("_AIL_redbook_position                 %x\n", lpfn_AIL_redbook_position);
		WriteLog("_AIL_redbook_play                     %x\n", lpfn_AIL_redbook_play);
		WriteLog("_AIL_redbook_stop                     %x\n", lpfn_AIL_redbook_stop);
		WriteLog("_AIL_redbook_pause                    %x\n", lpfn_AIL_redbook_pause);
		WriteLog("_AIL_redbook_resume                   %x\n", lpfn_AIL_redbook_resume);
		WriteLog("_AIL_redbook_volume_level             %x\n", lpfn_AIL_redbook_volume_level);
		WriteLog("_AIL_redbook_set_volume_level         %x\n", lpfn_AIL_redbook_set_volume_level);
		WriteLog("_AIL_quick_startup                    %x\n", lpfn_AIL_quick_startup);
		WriteLog("_AIL_quick_shutdown                   %x\n", lpfn_AIL_quick_shutdown);
		WriteLog("_AIL_quick_handles                    %x\n", lpfn_AIL_quick_handles);
		WriteLog("_AIL_quick_load                       %x\n", lpfn_AIL_quick_load);
		WriteLog("_AIL_quick_load_mem                   %x\n", lpfn_AIL_quick_load_mem);
		WriteLog("_AIL_quick_copy                       %x\n", lpfn_AIL_quick_copy);
		WriteLog("_AIL_quick_unload                     %x\n", lpfn_AIL_quick_unload);
		WriteLog("_AIL_quick_play                       %x\n", lpfn_AIL_quick_play);
		WriteLog("_AIL_quick_halt                       %x\n", lpfn_AIL_quick_halt);
		WriteLog("_AIL_quick_status                     %x\n", lpfn_AIL_quick_status);
		WriteLog("_AIL_quick_load_and_play              %x\n", lpfn_AIL_quick_load_and_play);
		WriteLog("_AIL_quick_set_speed                  %x\n", lpfn_AIL_quick_set_speed);
		WriteLog("_AIL_quick_set_volume                 %x\n", lpfn_AIL_quick_set_volume);
		WriteLog("_AIL_quick_set_reverb_levels          %x\n", lpfn_AIL_quick_set_reverb_levels);
		WriteLog("_AIL_quick_set_low_pass_cut_off       %x\n", lpfn_AIL_quick_set_low_pass_cut_off);
		WriteLog("_AIL_open_stream                      %x\n", lpfn_AIL_open_stream);
		WriteLog("_AIL_close_stream                     %x\n", lpfn_AIL_close_stream);
		WriteLog("_AIL_service_stream                   %x\n", lpfn_AIL_service_stream);
		WriteLog("_AIL_start_stream                     %x\n", lpfn_AIL_start_stream);
		WriteLog("_AIL_pause_stream                     %x\n", lpfn_AIL_pause_stream);
		WriteLog("_AIL_set_stream_volume_pan            %x\n", lpfn_AIL_set_stream_volume_pan);
		WriteLog("_AIL_set_stream_volume_levels         %x\n", lpfn_AIL_set_stream_volume_levels);
		WriteLog("_AIL_set_stream_reverb_levels         %x\n", lpfn_AIL_set_stream_reverb_levels);
		WriteLog("_AIL_set_stream_low_pass_cut_off      %x\n", lpfn_AIL_set_stream_low_pass_cut_off);
		WriteLog("_AIL_stream_volume_pan                %x\n", lpfn_AIL_stream_volume_pan);
		WriteLog("_AIL_stream_volume_levels             %x\n", lpfn_AIL_stream_volume_levels);
		WriteLog("_AIL_stream_reverb_levels             %x\n", lpfn_AIL_stream_reverb_levels);
		WriteLog("_AIL_stream_low_pass_cut_off          %x\n", lpfn_AIL_stream_low_pass_cut_off);
		WriteLog("_AIL_set_stream_playback_rate         %x\n", lpfn_AIL_set_stream_playback_rate);
		WriteLog("_AIL_stream_playback_rate             %x\n", lpfn_AIL_stream_playback_rate);
		WriteLog("_AIL_stream_loop_count                %x\n", lpfn_AIL_stream_loop_count);
		WriteLog("_AIL_set_stream_loop_block            %x\n", lpfn_AIL_set_stream_loop_block);
		WriteLog("_AIL_set_stream_loop_count            %x\n", lpfn_AIL_set_stream_loop_count);
		WriteLog("_AIL_stream_status                    %x\n", lpfn_AIL_stream_status);
		WriteLog("_AIL_set_stream_position              %x\n", lpfn_AIL_set_stream_position);
		WriteLog("_AIL_stream_position                  %x\n", lpfn_AIL_stream_position);
		WriteLog("_AIL_stream_info                      %x\n", lpfn_AIL_stream_info);
		WriteLog("_AIL_register_stream_callback         %x\n", lpfn_AIL_register_stream_callback);
		WriteLog("_AIL_auto_service_stream              %x\n", lpfn_AIL_auto_service_stream);
		WriteLog("_AIL_set_stream_user_data             %x\n", lpfn_AIL_set_stream_user_data);
		WriteLog("_AIL_stream_user_data                 %x\n", lpfn_AIL_stream_user_data);
		WriteLog("_AIL_DLS_open                         %x\n", lpfn_AIL_DLS_open);
		WriteLog("_AIL_DLS_close                        %x\n", lpfn_AIL_DLS_close);
		WriteLog("_AIL_DLS_load_file                    %x\n", lpfn_AIL_DLS_load_file);
		WriteLog("_AIL_DLS_load_memory                  %x\n", lpfn_AIL_DLS_load_memory);
		WriteLog("_AIL_DLS_unload                       %x\n", lpfn_AIL_DLS_unload);
		WriteLog("_AIL_DLS_compact                      %x\n", lpfn_AIL_DLS_compact);
		WriteLog("_AIL_DLS_set_reverb_levels            %x\n", lpfn_AIL_DLS_set_reverb_levels);
		WriteLog("_AIL_DLS_get_reverb_levels            %x\n", lpfn_AIL_DLS_get_reverb_levels);
		WriteLog("_AIL_DLS_get_info                     %x\n", lpfn_AIL_DLS_get_info);
		WriteLog("_AIL_set_sequence_ms_position         %x\n", lpfn_AIL_set_sequence_ms_position);
		WriteLog("_AIL_sequence_ms_position             %x\n", lpfn_AIL_sequence_ms_position);
		WriteLog("_AIL_sample_ms_position               %x\n", lpfn_AIL_sample_ms_position);
		WriteLog("_AIL_set_sample_ms_position           %x\n", lpfn_AIL_set_sample_ms_position);
		WriteLog("_AIL_stream_ms_position               %x\n", lpfn_AIL_stream_ms_position);
		WriteLog("_AIL_set_stream_ms_position           %x\n", lpfn_AIL_set_stream_ms_position);
		WriteLog("_AIL_quick_set_ms_position            %x\n", lpfn_AIL_quick_set_ms_position);
		WriteLog("_AIL_quick_ms_position                %x\n", lpfn_AIL_quick_ms_position);
		WriteLog("_AIL_quick_ms_length                  %x\n", lpfn_AIL_quick_ms_length);
		WriteLog("_AIL_quick_type                       %x\n", lpfn_AIL_quick_type);
		WriteLog("_AIL_MIDI_to_XMI                      %x\n", lpfn_AIL_MIDI_to_XMI);
		WriteLog("_AIL_compress_ADPCM                   %x\n", lpfn_AIL_compress_ADPCM);
		WriteLog("_AIL_decompress_ADPCM                 %x\n", lpfn_AIL_decompress_ADPCM);
		WriteLog("_AIL_WAV_info                         %x\n", lpfn_AIL_WAV_info);
		WriteLog("_AIL_file_type                        %x\n", lpfn_AIL_file_type);
		WriteLog("_AIL_find_DLS                         %x\n", lpfn_AIL_find_DLS);
		WriteLog("_AIL_extract_DLS                      %x\n", lpfn_AIL_extract_DLS);
		WriteLog("_AIL_primary_digital_driver           %x\n", lpfn_AIL_primary_digital_driver);
		WriteLog("_AIL_enumerate_filters                %x\n", lpfn_AIL_enumerate_filters);
		WriteLog("_AIL_open_filter                      %x\n", lpfn_AIL_open_filter);
		WriteLog("_AIL_close_filter                     %x\n", lpfn_AIL_close_filter);
		WriteLog("_AIL_enumerate_filter_attributes      %x\n", lpfn_AIL_enumerate_filter_attributes);
		WriteLog("_AIL_enumerate_filter_sample_attribute%x\n", lpfn_AIL_enumerate_filter_sample_attribute);
		WriteLog("_AIL_filter_attribute                 %x\n", lpfn_AIL_filter_attribute);
		WriteLog("_AIL_filter_sample_attribute          %x\n", lpfn_AIL_filter_sample_attribute);
		WriteLog("_AIL_filter_stream_attribute          %x\n", lpfn_AIL_filter_stream_attribute);
		WriteLog("_AIL_filter_DLS_attribute             %x\n", lpfn_AIL_filter_DLS_attribute);
		WriteLog("_AIL_set_filter_preference            %x\n", lpfn_AIL_set_filter_preference);
		WriteLog("_AIL_set_filter_sample_preference     %x\n", lpfn_AIL_set_filter_sample_preference);
		WriteLog("_AIL_set_filter_stream_preference     %x\n", lpfn_AIL_set_filter_stream_preference);
		WriteLog("_AIL_set_filter_DLS_preference        %x\n", lpfn_AIL_set_filter_DLS_preference);
		WriteLog("_AIL_enumerate_3D_providers           %x\n", lpfn_AIL_enumerate_3D_providers);
		WriteLog("_AIL_open_3D_provider                 %x\n", lpfn_AIL_open_3D_provider);
		WriteLog("_AIL_close_3D_provider                %x\n", lpfn_AIL_close_3D_provider);
		WriteLog("_AIL_enumerate_3D_provider_attributes %x\n", lpfn_AIL_enumerate_3D_provider_attributes);
		WriteLog("_AIL_enumerate_3D_sample_attributes   %x\n", lpfn_AIL_enumerate_3D_sample_attributes);
		WriteLog("_AIL_3D_provider_attribute            %x\n", lpfn_AIL_3D_provider_attribute);
		WriteLog("_AIL_3D_sample_attribute              %x\n", lpfn_AIL_3D_sample_attribute);
		WriteLog("_AIL_set_3D_provider_preference       %x\n", lpfn_AIL_set_3D_provider_preference);
		WriteLog("_AIL_set_3D_sample_preference         %x\n", lpfn_AIL_set_3D_sample_preference);
		WriteLog("_AIL_allocate_3D_sample_handle        %x\n", lpfn_AIL_allocate_3D_sample_handle);
		WriteLog("_AIL_release_3D_sample_handle         %x\n", lpfn_AIL_release_3D_sample_handle);
		WriteLog("_AIL_start_3D_sample                  %x\n", lpfn_AIL_start_3D_sample);
		WriteLog("_AIL_stop_3D_sample                   %x\n", lpfn_AIL_stop_3D_sample);
		WriteLog("_AIL_resume_3D_sample                 %x\n", lpfn_AIL_resume_3D_sample);
		WriteLog("_AIL_end_3D_sample                    %x\n", lpfn_AIL_end_3D_sample);
		WriteLog("_AIL_set_3D_sample_info               %x\n", lpfn_AIL_set_3D_sample_info);
		WriteLog("_AIL_set_3D_sample_file               %x\n", lpfn_AIL_set_3D_sample_file);
		WriteLog("_AIL_set_3D_sample_volume             %x\n", lpfn_AIL_set_3D_sample_volume);
		WriteLog("_AIL_set_3D_sample_playback_rate      %x\n", lpfn_AIL_set_3D_sample_playback_rate);
		WriteLog("_AIL_set_3D_sample_offset             %x\n", lpfn_AIL_set_3D_sample_offset);
		WriteLog("_AIL_set_3D_sample_loop_count         %x\n", lpfn_AIL_set_3D_sample_loop_count);
		WriteLog("_AIL_set_3D_sample_loop_block         %x\n", lpfn_AIL_set_3D_sample_loop_block);
		WriteLog("_AIL_set_3D_sample_obstruction        %x\n", lpfn_AIL_set_3D_sample_obstruction);
		WriteLog("_AIL_set_3D_sample_exclusion          %x\n", lpfn_AIL_set_3D_sample_exclusion);
		WriteLog("_AIL_set_3D_sample_occlusion          %x\n", lpfn_AIL_set_3D_sample_occlusion);
		WriteLog("_AIL_set_3D_sample_cone               %x\n", lpfn_AIL_set_3D_sample_cone);
		WriteLog("_AIL_set_3D_sample_effects_level      %x\n", lpfn_AIL_set_3D_sample_effects_level);
		WriteLog("_AIL_register_3D_EOS_callback         %x\n", lpfn_AIL_register_3D_EOS_callback);
		WriteLog("_AIL_3D_sample_obstruction            %x\n", lpfn_AIL_3D_sample_obstruction);
		WriteLog("_AIL_3D_sample_exclusion              %x\n", lpfn_AIL_3D_sample_exclusion);
		WriteLog("_AIL_3D_sample_occlusion              %x\n", lpfn_AIL_3D_sample_occlusion);
		WriteLog("_AIL_3D_sample_cone                   %x\n", lpfn_AIL_3D_sample_cone);
		WriteLog("_AIL_3D_sample_effects_level          %x\n", lpfn_AIL_3D_sample_effects_level);
		WriteLog("_AIL_3D_sample_status                 %x\n", lpfn_AIL_3D_sample_status);
		WriteLog("_AIL_3D_sample_volume                 %x\n", lpfn_AIL_3D_sample_volume);
		WriteLog("_AIL_3D_sample_playback_rate          %x\n", lpfn_AIL_3D_sample_playback_rate);
		WriteLog("_AIL_3D_sample_offset                 %x\n", lpfn_AIL_3D_sample_offset);
		WriteLog("_AIL_3D_sample_length                 %x\n", lpfn_AIL_3D_sample_length);
		WriteLog("_AIL_3D_sample_loop_count             %x\n", lpfn_AIL_3D_sample_loop_count);
		WriteLog("_AIL_set_3D_sample_distances          %x\n", lpfn_AIL_set_3D_sample_distances);
		WriteLog("_AIL_3D_sample_distances              %x\n", lpfn_AIL_3D_sample_distances);
		WriteLog("_AIL_set_3D_user_data                 %x\n", lpfn_AIL_set_3D_user_data);
		WriteLog("_AIL_3D_user_data                     %x\n", lpfn_AIL_3D_user_data);
		WriteLog("_AIL_active_3D_sample_count           %x\n", lpfn_AIL_active_3D_sample_count);
		WriteLog("_AIL_3D_room_type                     %x\n", lpfn_AIL_3D_room_type);
		WriteLog("_AIL_set_3D_room_type                 %x\n", lpfn_AIL_set_3D_room_type);
		WriteLog("_AIL_3D_speaker_type                  %x\n", lpfn_AIL_3D_speaker_type);
		WriteLog("_AIL_set_3D_speaker_type              %x\n", lpfn_AIL_set_3D_speaker_type);
		WriteLog("_AIL_3D_rolloff_factor                %x\n", lpfn_AIL_3D_rolloff_factor);
		WriteLog("_AIL_set_3D_rolloff_factor            %x\n", lpfn_AIL_set_3D_rolloff_factor);
		WriteLog("_AIL_3D_doppler_factor                %x\n", lpfn_AIL_3D_doppler_factor);
		WriteLog("_AIL_set_3D_doppler_factor            %x\n", lpfn_AIL_set_3D_doppler_factor);
		WriteLog("_AIL_3D_distance_factor               %x\n", lpfn_AIL_3D_distance_factor);
		WriteLog("_AIL_set_3D_distance_factor           %x\n", lpfn_AIL_set_3D_distance_factor);
		WriteLog("_AIL_open_3D_listener                 %x\n", lpfn_AIL_open_3D_listener);
		WriteLog("_AIL_close_3D_listener                %x\n", lpfn_AIL_close_3D_listener);
		WriteLog("_AIL_open_3D_object                   %x\n", lpfn_AIL_open_3D_object);
		WriteLog("_AIL_close_3D_object                  %x\n", lpfn_AIL_close_3D_object);
		WriteLog("_AIL_set_3D_position                  %x\n", lpfn_AIL_set_3D_position);
		WriteLog("_AIL_set_3D_velocity                  %x\n", lpfn_AIL_set_3D_velocity);
		WriteLog("_AIL_set_3D_velocity_vector           %x\n", lpfn_AIL_set_3D_velocity_vector);
		WriteLog("_AIL_set_3D_orientation               %x\n", lpfn_AIL_set_3D_orientation);
		WriteLog("_AIL_3D_position                      %x\n", lpfn_AIL_3D_position);
		WriteLog("_AIL_3D_velocity                      %x\n", lpfn_AIL_3D_velocity);
		WriteLog("_AIL_3D_orientation                   %x\n", lpfn_AIL_3D_orientation);
		WriteLog("_AIL_update_3D_position               %x\n", lpfn_AIL_update_3D_position);
		WriteLog("_AIL_auto_update_3D_position          %x\n", lpfn_AIL_auto_update_3D_position);
		WriteLog("_AIL_size_processed_digital_audio     %x\n", lpfn_AIL_size_processed_digital_audio);
		WriteLog("_AIL_process_digital_audio            %x\n", lpfn_AIL_process_digital_audio);
		WriteLog("_AIL_merge_DLS_with_XMI               %x\n", lpfn_AIL_merge_DLS_with_XMI);
		WriteLog("_AIL_compress_DLS                     %x\n", lpfn_AIL_compress_DLS);
		WriteLog("_AIL_filter_DLS_with_XMI              %x\n", lpfn_AIL_filter_DLS_with_XMI);
		WriteLog("_AIL_compress_ASI                     %x\n", lpfn_AIL_compress_ASI);
		WriteLog("_AIL_decompress_ASI                   %x\n", lpfn_AIL_decompress_ASI);
		WriteLog("_AIL_request_EOB_ASI_reset            %x\n", lpfn_AIL_request_EOB_ASI_reset);
		WriteLog("_AIL_set_redist_directory             %x\n", lpfn_AIL_set_redist_directory);
		WriteLog("_MIX_RIB_MAIN                         %x\n", lpfn_MIX_RIB_MAIN);
		WriteLog("_AIL_mem_use_malloc                   %x\n", lpfn_AIL_mem_use_malloc);
		WriteLog("_AIL_mem_use_free                     %x\n", lpfn_AIL_mem_use_free);
		WriteLog("AIL_sprintf                           %x\n", lpfnAIL_sprintf);
		WriteLog("DLSMSSOpen                            %x\n", lpfnDLSMSSOpen);
		WriteLog("DLSClose                              %x\n", lpfnDLSClose);
		WriteLog("DLSLoadFile                           %x\n", lpfnDLSLoadFile);
		WriteLog("DLSLoadMemFile                        %x\n", lpfnDLSLoadMemFile);
		WriteLog("DLSGetInfo                            %x\n", lpfnDLSGetInfo);
		WriteLog("DLSCompactMemory                      %x\n", lpfnDLSCompactMemory);
		WriteLog("DLSUnloadAll                          %x\n", lpfnDLSUnloadAll);
		WriteLog("DLSUnloadFile                         %x\n", lpfnDLSUnloadFile);
		WriteLog("DLSSetAttribute                       %x\n", lpfnDLSSetAttribute);
		WriteLog("_DLSMSSGetCPU                         %x\n", lpfn_DLSMSSGetCPU);
		WriteLog("-- Mss32.dll Export Table Log End --\n");

		DebugLog("Mss32.DLX ���Ͽ��� �ͽ���Ʈ �ּҸ� ��µ� �����߽��ϴ�.\n");
		WriteLog("Mss32 Hook ��ġ�� �����߽��ϴ�.\n");
		return false;
	}
	WriteLog("Mss32 Hook ��ġ�� ���ƽ��ϴ�.\n");
	return true;
}

void CMSSHook::SetSSQuality(int quality)
{
	ssQuality = quality;
}

int CMSSHook::GetSSQuality(void)
{
	return ssQuality;
}

NAKED VOID __stdcall AIL_get_preference(BYTE)
{
	__asm JMP lpfn_AIL_get_preference
}
NAKED VOID __stdcall AIL_lock(VOID)
{
	__asm JMP lpfn_AIL_lock
}
NAKED VOID __stdcall AIL_unlock(VOID)
{
	__asm JMP lpfn_AIL_unlock
}
NAKED VOID __stdcall AIL_lock_mutex(VOID)
{
	__asm JMP lpfn_AIL_lock_mutex
}
NAKED VOID __stdcall AIL_unlock_mutex(VOID)
{
	__asm JMP lpfn_AIL_unlock_mutex
}
NAKED VOID __stdcall AIL_get_timer_highest_delay(VOID)
{
	__asm JMP lpfn_AIL_get_timer_highest_delay
}
/*
NAKED VOID __stdcall DllMain(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_DllMain
}
*/
NAKED VOID __stdcall RIB_load_static_provider_library(BYTE, BYTE)
{
	__asm JMP lpfn_RIB_load_static_provider_library
}
NAKED VOID RIB_alloc_provider_handle(VOID)
{
	__asm JMP lpfnRIB_alloc_provider_handle
}
NAKED VOID RIB_free_provider_handle(VOID)
{
	__asm JMP lpfnRIB_free_provider_handle
}
NAKED VOID RIB_load_provider_library(VOID)
{
	__asm JMP lpfnRIB_load_provider_library
}
NAKED VOID RIB_free_provider_library(VOID)
{
	__asm JMP lpfnRIB_free_provider_library
}
NAKED VOID RIB_register_interface(VOID)
{
	__asm JMP lpfnRIB_register_interface
}
NAKED VOID RIB_request_interface(VOID)
{
	__asm JMP lpfnRIB_request_interface
}
NAKED VOID RIB_request_interface_entry(VOID)
{
	__asm JMP lpfnRIB_request_interface_entry
}
NAKED VOID RIB_unregister_interface(VOID)
{
	__asm JMP lpfnRIB_unregister_interface
}
NAKED VOID RIB_enumerate_interface(VOID)
{
	__asm JMP lpfnRIB_enumerate_interface
}
NAKED VOID __stdcall RIB_enumerate_providers(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_enumerate_providers
}
NAKED VOID RIB_type_string(VOID)
{
	__asm JMP lpfnRIB_type_string
}
NAKED VOID RIB_find_file_provider(void)
{
	__asm JMP lpfnRIB_find_file_provider
}
NAKED VOID __stdcall RIB_find_files_provider(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_find_files_provider
}
NAKED VOID __stdcall RIB_find_file_dec_provider(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_find_file_dec_provider
}
NAKED VOID __stdcall RIB_find_provider(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_find_provider
}
NAKED VOID __stdcall RIB_load_application_providers(BYTE)
{
	__asm JMP lpfn_RIB_load_application_providers
}
NAKED VOID __stdcall RIB_set_provider_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_set_provider_user_data
}
NAKED VOID __stdcall RIB_provider_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_RIB_provider_user_data
}
NAKED VOID __stdcall RIB_set_provider_system_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_RIB_set_provider_system_data
}
NAKED VOID __stdcall RIB_provider_system_data(BYTE, BYTE)
{
	__asm JMP lpfn_RIB_provider_system_data
}
NAKED VOID  RIB_error(void)
{
	__asm JMP lpfnRIB_error
}
NAKED VOID __stdcall AIL_set_file_async_callbacks(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_file_async_callbacks
}
NAKED VOID __stdcall AIL_set_file_callbacks(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_file_callbacks
}
NAKED VOID __stdcall AIL_list_DLS(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_list_DLS
}
NAKED VOID __stdcall AIL_list_MIDI(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_list_MIDI
}
NAKED VOID stream_background(void)
{
	__asm JMP lpfnstream_background
}
NAKED VOID __stdcall AIL_ms_count(VOID)
{
	__asm JMP lpfn_AIL_ms_count
}
NAKED VOID __stdcall AIL_us_count(VOID)
{
	__asm JMP lpfn_AIL_us_count
}
NAKED VOID __stdcall AIL_MMX_available(VOID)
{
	__asm JMP lpfn_AIL_MMX_available
}
NAKED VOID AIL_debug_printf(VOID)
{
	__asm JMP lpfnAIL_debug_printf
}
NAKED VOID __stdcall AIL_startup(VOID)
{
	__asm JMP lpfn_AIL_startup
}
NAKED VOID __stdcall AIL_shutdown(VOID)
{
	__asm JMP lpfn_AIL_shutdown
}
NAKED VOID __stdcall AIL_HWND(VOID)
{
	__asm JMP lpfn_AIL_HWND
}
NAKED VOID __stdcall AIL_mem_alloc_lock(BYTE)
{
	__asm JMP lpfn_AIL_mem_alloc_lock
}
NAKED VOID __stdcall AIL_mem_free_lock(BYTE)
{
	__asm JMP lpfn_AIL_mem_free_lock
}
NAKED VOID __stdcall AIL_set_preference(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_preference
}
NAKED VOID __stdcall AIL_last_error(VOID)
{
	__asm JMP lpfn_AIL_last_error
}
NAKED VOID __stdcall AIL_set_error(BYTE)
{
	__asm JMP lpfn_AIL_set_error
}
NAKED VOID __stdcall AIL_delay(BYTE)
{
	__asm JMP lpfn_AIL_delay
}
NAKED VOID __stdcall AIL_background(VOID)
{
	__asm JMP lpfn_AIL_background
}
NAKED VOID __stdcall AIL_register_timer(BYTE)
{
	__asm JMP lpfn_AIL_register_timer
}
NAKED VOID __stdcall AIL_set_timer_user(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_timer_user
}
NAKED VOID __stdcall AIL_set_timer_period(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_timer_period
}
NAKED VOID __stdcall AIL_set_timer_frequency(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_timer_frequency
}
NAKED VOID __stdcall AIL_set_timer_divisor(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_timer_divisor
}
NAKED VOID __stdcall AIL_start_timer(BYTE)
{
	__asm JMP lpfn_AIL_start_timer
}
NAKED VOID __stdcall AIL_start_all_timers(VOID)
{
	__asm JMP lpfn_AIL_start_all_timers
}
NAKED VOID __stdcall AIL_stop_timer(BYTE)
{
	__asm JMP lpfn_AIL_stop_timer
}
NAKED VOID __stdcall AIL_stop_all_timers(VOID)
{
	__asm JMP lpfn_AIL_stop_all_timers
}
NAKED VOID __stdcall AIL_release_timer_handle(BYTE)
{
	__asm JMP lpfn_AIL_release_timer_handle
}
NAKED VOID __stdcall AIL_release_all_timers(VOID)
{
	__asm JMP lpfn_AIL_release_all_timers
}
NAKED VOID __stdcall AIL_open_digital_driver(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_open_digital_driver
}
NAKED VOID __stdcall AIL_close_digital_driver(BYTE)
{
	__asm JMP lpfn_AIL_close_digital_driver
}
NAKED VOID __stdcall AIL_waveOutOpen(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_waveOutOpen
}
NAKED VOID __stdcall AIL_waveOutClose(BYTE)
{
	__asm JMP lpfn_AIL_waveOutClose
}
NAKED VOID __stdcall AIL_digital_handle_release(BYTE)
{
	__asm JMP lpfn_AIL_digital_handle_release
}
NAKED VOID __stdcall AIL_digital_handle_reacquire(BYTE)
{
	__asm JMP lpfn_AIL_digital_handle_reacquire
}
NAKED VOID __stdcall AIL_open_input(BYTE)
{
	__asm JMP lpfn_AIL_open_input
}
NAKED VOID __stdcall AIL_close_input(BYTE)
{
	__asm JMP lpfn_AIL_close_input
}
NAKED VOID __stdcall AIL_get_input_info(BYTE)
{
	__asm JMP lpfn_AIL_get_input_info
}
NAKED VOID __stdcall AIL_set_input_state(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_input_state
}
NAKED VOID __stdcall AIL_digital_CPU_percent(BYTE)
{
	__asm JMP lpfn_AIL_digital_CPU_percent
}
NAKED VOID __stdcall AIL_digital_latency(BYTE)
{
	__asm JMP lpfn_AIL_digital_latency
}
NAKED VOID __stdcall AIL_allocate_sample_handle(BYTE)
{
	__asm JMP lpfn_AIL_allocate_sample_handle
}
NAKED VOID __stdcall AIL_allocate_file_sample(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_allocate_file_sample
}
NAKED VOID __stdcall AIL_release_sample_handle(BYTE)
{
	__asm JMP lpfn_AIL_release_sample_handle
}
NAKED VOID __stdcall AIL_init_sample(BYTE)
{
	__asm JMP lpfn_AIL_init_sample
}
NAKED VOID __stdcall AIL_set_sample_file(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_file
}
NAKED VOID __stdcall AIL_set_named_sample_file(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_named_sample_file
}
NAKED VOID __stdcall AIL_set_sample_processor(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_processor
}
NAKED VOID __stdcall AIL_set_stream_processor(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_processor
}
NAKED VOID __stdcall AIL_set_DLS_processor(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_DLS_processor
}
NAKED VOID __stdcall AIL_set_digital_driver_processor(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_driver_processor
}
NAKED VOID __stdcall AIL_set_sample_address(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_address
}
NAKED VOID __stdcall AIL_set_sample_type(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_type
}
NAKED VOID __stdcall AIL_set_sample_adpcm_block_size(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_adpcm_block_size
}
NAKED VOID __stdcall AIL_start_sample(BYTE)
{
	__asm JMP lpfn_AIL_start_sample
}
NAKED VOID __stdcall AIL_stop_sample(BYTE)
{
	__asm JMP lpfn_AIL_stop_sample
}
NAKED VOID __stdcall AIL_resume_sample(BYTE)
{
	__asm JMP lpfn_AIL_resume_sample
}
NAKED VOID __stdcall AIL_end_sample(BYTE)
{
	__asm JMP lpfn_AIL_end_sample
}
NAKED VOID __stdcall AIL_set_sample_playback_rate(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_playback_rate
}
NAKED VOID __stdcall AIL_set_sample_volume_pan(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_volume_pan
}
NAKED VOID __stdcall AIL_set_sample_volume_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_volume_levels
}
NAKED VOID __stdcall AIL_set_sample_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_reverb_levels
}
NAKED VOID __stdcall AIL_set_sample_low_pass_cut_off(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_low_pass_cut_off
}
NAKED VOID __stdcall AIL_set_sample_loop_count(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_loop_count
}
NAKED VOID __stdcall AIL_set_sample_loop_block(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_loop_block
}
NAKED VOID __stdcall AIL_sample_status(BYTE)
{
	__asm JMP lpfn_AIL_sample_status
}
NAKED VOID __stdcall AIL_sample_playback_rate(BYTE)
{
	__asm JMP lpfn_AIL_sample_playback_rate
}
NAKED VOID __stdcall AIL_sample_volume_pan(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_volume_pan
}
NAKED VOID __stdcall AIL_sample_volume_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_volume_levels
}
NAKED VOID __stdcall AIL_sample_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_reverb_levels
}
NAKED VOID __stdcall AIL_sample_low_pass_cut_off(BYTE)
{
	__asm JMP lpfn_AIL_sample_low_pass_cut_off
}
NAKED VOID __stdcall AIL_sample_loop_count(BYTE)
{
	__asm JMP lpfn_AIL_sample_loop_count
}
NAKED VOID __stdcall AIL_set_digital_master_volume_level(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_master_volume_level
}
NAKED VOID __stdcall AIL_digital_master_volume_level(BYTE)
{
	__asm JMP lpfn_AIL_digital_master_volume_level
}
NAKED VOID __stdcall AIL_set_digital_master_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_master_reverb_levels
}
NAKED VOID __stdcall AIL_set_digital_master_room_type(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_master_room_type
}
NAKED VOID __stdcall AIL_digital_master_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_digital_master_reverb_levels
}
NAKED VOID __stdcall AIL_set_digital_master_reverb(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_digital_master_reverb
}
NAKED VOID __stdcall AIL_digital_master_reverb(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_digital_master_reverb
}
NAKED VOID __stdcall AIL_minimum_sample_buffer_size(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_minimum_sample_buffer_size
}
NAKED VOID __stdcall AIL_sample_buffer_ready(BYTE)
{
	__asm JMP lpfn_AIL_sample_buffer_ready
}
NAKED VOID __stdcall AIL_load_sample_buffer(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_load_sample_buffer
}
NAKED VOID __stdcall AIL_sample_buffer_info(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_buffer_info
}
NAKED VOID __stdcall AIL_sample_granularity(BYTE)
{
	__asm JMP lpfn_AIL_sample_granularity
}
NAKED VOID __stdcall AIL_set_sample_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_position
}
NAKED VOID __stdcall AIL_sample_position(BYTE)
{
	__asm JMP lpfn_AIL_sample_position
}
NAKED VOID __stdcall AIL_register_SOB_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_SOB_callback
}
NAKED VOID __stdcall AIL_register_EOB_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_EOB_callback
}
NAKED VOID __stdcall AIL_register_EOS_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_EOS_callback
}
NAKED VOID __stdcall AIL_register_EOF_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_EOF_callback
}
NAKED VOID __stdcall AIL_set_sample_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_user_data
}
NAKED VOID __stdcall AIL_sample_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_user_data
}
NAKED VOID __stdcall AIL_active_sample_count(BYTE)
{
	__asm JMP lpfn_AIL_active_sample_count
}
NAKED VOID __stdcall AIL_digital_configuration(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_digital_configuration
}
NAKED VOID __stdcall AIL_get_DirectSound_info(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_get_DirectSound_info
}
NAKED VOID __stdcall AIL_set_DirectSound_HWND(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_DirectSound_HWND
}
NAKED VOID __stdcall AIL_open_XMIDI_driver(BYTE)
{
	__asm JMP lpfn_AIL_open_XMIDI_driver
}
NAKED VOID __stdcall AIL_close_XMIDI_driver(BYTE)
{
	__asm JMP lpfn_AIL_close_XMIDI_driver
}
NAKED VOID __stdcall AIL_midiOutOpen(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_midiOutOpen
}
NAKED VOID __stdcall AIL_midiOutClose(BYTE)
{
	__asm JMP lpfn_AIL_midiOutClose
}
NAKED VOID __stdcall AIL_MIDI_handle_release(BYTE)
{
	__asm JMP lpfn_AIL_MIDI_handle_release
}
NAKED VOID __stdcall AIL_MIDI_handle_reacquire(BYTE)
{
	__asm JMP lpfn_AIL_MIDI_handle_reacquire
}
NAKED VOID __stdcall AIL_allocate_sequence_handle(BYTE)
{
	__asm JMP lpfn_AIL_allocate_sequence_handle
}
NAKED VOID __stdcall AIL_release_sequence_handle(BYTE)
{
	__asm JMP lpfn_AIL_release_sequence_handle
}
NAKED VOID __stdcall AIL_init_sequence(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_init_sequence
}
NAKED VOID __stdcall AIL_start_sequence(BYTE)
{
	__asm JMP lpfn_AIL_start_sequence
}
NAKED VOID __stdcall AIL_stop_sequence(BYTE)
{
	__asm JMP lpfn_AIL_stop_sequence
}
NAKED VOID __stdcall AIL_resume_sequence(BYTE)
{
	__asm JMP lpfn_AIL_resume_sequence
}
NAKED VOID __stdcall AIL_end_sequence(BYTE)
{
	__asm JMP lpfn_AIL_end_sequence
}
NAKED VOID __stdcall AIL_set_sequence_tempo(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_tempo
}
NAKED VOID __stdcall AIL_set_sequence_volume(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_volume
}
NAKED VOID __stdcall AIL_set_sequence_loop_count(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_loop_count
}
NAKED VOID __stdcall AIL_sequence_status(BYTE)
{
	__asm JMP lpfn_AIL_sequence_status
}
NAKED VOID __stdcall AIL_sequence_tempo(BYTE)
{
	__asm JMP lpfn_AIL_sequence_tempo
}
NAKED VOID __stdcall AIL_sequence_volume(BYTE)
{
	__asm JMP lpfn_AIL_sequence_volume
}
NAKED VOID __stdcall AIL_sequence_loop_count(BYTE)
{
	__asm JMP lpfn_AIL_sequence_loop_count
}
NAKED VOID __stdcall AIL_set_XMIDI_master_volume(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_XMIDI_master_volume
}
NAKED VOID __stdcall AIL_XMIDI_master_volume(BYTE)
{
	__asm JMP lpfn_AIL_XMIDI_master_volume
}
NAKED VOID __stdcall AIL_active_sequence_count(BYTE)
{
	__asm JMP lpfn_AIL_active_sequence_count
}
NAKED VOID __stdcall AIL_controller_value(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_controller_value
}
NAKED VOID __stdcall AIL_channel_notes(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_channel_notes
}
NAKED VOID __stdcall AIL_sequence_position(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sequence_position
}
NAKED VOID __stdcall AIL_branch_index(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_branch_index
}
NAKED VOID __stdcall AIL_register_prefix_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_prefix_callback
}
NAKED VOID __stdcall AIL_register_trigger_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_trigger_callback
}
NAKED VOID __stdcall AIL_register_sequence_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_sequence_callback
}
NAKED VOID __stdcall AIL_register_beat_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_beat_callback
}
NAKED VOID __stdcall AIL_register_event_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_event_callback
}
NAKED VOID __stdcall AIL_register_timbre_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_timbre_callback
}
NAKED VOID __stdcall AIL_set_sequence_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_user_data
}
NAKED VOID __stdcall AIL_sequence_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sequence_user_data
}
NAKED VOID __stdcall AIL_register_ICA_array(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_ICA_array
}
NAKED VOID __stdcall AIL_lock_channel(BYTE)
{
	__asm JMP lpfn_AIL_lock_channel
}
NAKED VOID __stdcall AIL_release_channel(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_release_channel
}
NAKED VOID __stdcall AIL_map_sequence_channel(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_map_sequence_channel
}
NAKED VOID __stdcall AIL_true_sequence_channel(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_true_sequence_channel
}
NAKED VOID __stdcall AIL_send_channel_voice_message(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_send_channel_voice_message
}
NAKED VOID __stdcall AIL_send_sysex_message(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_send_sysex_message
}
NAKED VOID __stdcall AIL_create_wave_synthesizer(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_create_wave_synthesizer
}
NAKED VOID __stdcall AIL_destroy_wave_synthesizer(BYTE)
{
	__asm JMP lpfn_AIL_destroy_wave_synthesizer
}
NAKED VOID __stdcall AIL_file_error(VOID)
{
	__asm JMP lpfn_AIL_file_error
}
NAKED VOID __stdcall AIL_file_size(BYTE)
{
	__asm JMP lpfn_AIL_file_size
}
NAKED VOID __stdcall AIL_file_read(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_file_read
}
NAKED VOID __stdcall AIL_file_write(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_file_write
}
NAKED VOID __stdcall AIL_WAV_file_write(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_WAV_file_write
}
NAKED VOID __stdcall AIL_serve(VOID)
{
	__asm JMP lpfn_AIL_serve
}
NAKED VOID __stdcall AIL_redbook_open(BYTE)
{
	__asm JMP lpfn_AIL_redbook_open
}
NAKED VOID __stdcall AIL_redbook_open_drive(BYTE)
{
	__asm JMP lpfn_AIL_redbook_open_drive
}
NAKED VOID __stdcall AIL_redbook_close(BYTE)
{
	__asm JMP lpfn_AIL_redbook_close
}
NAKED VOID __stdcall AIL_redbook_eject(BYTE)
{
	__asm JMP lpfn_AIL_redbook_eject
}
NAKED VOID __stdcall AIL_redbook_retract(BYTE)
{
	__asm JMP lpfn_AIL_redbook_retract
}
NAKED VOID __stdcall AIL_redbook_status(BYTE)
{
	__asm JMP lpfn_AIL_redbook_status
}
NAKED VOID __stdcall AIL_redbook_tracks(BYTE)
{
	__asm JMP lpfn_AIL_redbook_tracks
}
NAKED VOID __stdcall AIL_redbook_track(BYTE)
{
	__asm JMP lpfn_AIL_redbook_track
}
NAKED VOID __stdcall AIL_redbook_track_info(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_redbook_track_info
}
NAKED VOID __stdcall AIL_redbook_id(BYTE)
{
	__asm JMP lpfn_AIL_redbook_id
}
NAKED VOID __stdcall AIL_redbook_position(BYTE)
{
	__asm JMP lpfn_AIL_redbook_position
}
NAKED VOID __stdcall AIL_redbook_play(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_redbook_play
}
NAKED VOID __stdcall AIL_redbook_stop(BYTE)
{
	__asm JMP lpfn_AIL_redbook_stop
}
NAKED VOID __stdcall AIL_redbook_pause(BYTE)
{
	__asm JMP lpfn_AIL_redbook_pause
}
NAKED VOID __stdcall AIL_redbook_resume(BYTE)
{
	__asm JMP lpfn_AIL_redbook_resume
}
NAKED VOID __stdcall AIL_redbook_volume_level(BYTE)
{
	__asm JMP lpfn_AIL_redbook_volume_level
}
NAKED VOID __stdcall AIL_redbook_set_volume_level(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_redbook_set_volume_level
}
NAKED VOID __stdcall AIL_quick_startup(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_startup
}
NAKED VOID __stdcall AIL_quick_shutdown(VOID)
{
	__asm JMP lpfn_AIL_quick_shutdown
}
NAKED VOID __stdcall AIL_quick_handles(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_handles
}
NAKED VOID __stdcall AIL_quick_load(BYTE)
{
	__asm JMP lpfn_AIL_quick_load
}
NAKED VOID __stdcall AIL_quick_load_mem(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_load_mem
}
NAKED VOID __stdcall AIL_quick_copy(BYTE)
{
	__asm JMP lpfn_AIL_quick_copy
}
NAKED VOID __stdcall AIL_quick_unload(BYTE)
{
	__asm JMP lpfn_AIL_quick_unload
}
NAKED VOID __stdcall AIL_quick_play(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_play
}
NAKED VOID __stdcall AIL_quick_halt(BYTE)
{
	__asm JMP lpfn_AIL_quick_halt
}
NAKED VOID __stdcall AIL_quick_status(BYTE)
{
	__asm JMP lpfn_AIL_quick_status
}
NAKED VOID __stdcall AIL_quick_load_and_play(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_load_and_play
}
NAKED VOID __stdcall AIL_quick_set_speed(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_speed
}
NAKED VOID __stdcall AIL_quick_set_volume(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_volume
}
NAKED VOID __stdcall AIL_quick_set_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_reverb_levels
}
NAKED VOID __stdcall AIL_quick_set_low_pass_cut_off(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_low_pass_cut_off
}
NAKED VOID __stdcall AIL_open_stream(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_open_stream
}
NAKED VOID __stdcall AIL_close_stream(BYTE)
{
	__asm JMP lpfn_AIL_close_stream
}
NAKED VOID __stdcall AIL_service_stream(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_service_stream
}
NAKED VOID __stdcall AIL_start_stream(BYTE)
{
	__asm JMP lpfn_AIL_start_stream
}
NAKED VOID __stdcall AIL_pause_stream(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_pause_stream
}
NAKED VOID __stdcall AIL_set_stream_volume_pan(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_volume_pan
}
NAKED VOID __stdcall AIL_set_stream_volume_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_volume_levels
}
NAKED VOID __stdcall AIL_set_stream_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_reverb_levels
}
NAKED VOID __stdcall AIL_set_stream_low_pass_cut_off(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_low_pass_cut_off
}
NAKED VOID __stdcall AIL_stream_volume_pan(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_volume_pan
}
NAKED VOID __stdcall AIL_stream_volume_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_volume_levels
}
NAKED VOID __stdcall AIL_stream_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_reverb_levels
}
NAKED VOID __stdcall AIL_stream_low_pass_cut_off(BYTE)
{
	__asm JMP lpfn_AIL_stream_low_pass_cut_off
}
NAKED VOID __stdcall AIL_set_stream_playback_rate(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_playback_rate
}
NAKED VOID __stdcall AIL_stream_playback_rate(BYTE)
{
	__asm JMP lpfn_AIL_stream_playback_rate
}
NAKED VOID __stdcall AIL_stream_loop_count(BYTE)
{
	__asm JMP lpfn_AIL_stream_loop_count
}
NAKED VOID __stdcall AIL_set_stream_loop_block(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_loop_block
}
NAKED VOID __stdcall AIL_set_stream_loop_count(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_loop_count
}
NAKED VOID __stdcall AIL_stream_status(BYTE)
{
	__asm JMP lpfn_AIL_stream_status
}
NAKED VOID __stdcall AIL_set_stream_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_position
}
NAKED VOID __stdcall AIL_stream_position(BYTE)
{
	__asm JMP lpfn_AIL_stream_position
}
NAKED VOID __stdcall AIL_stream_info(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_info
}
NAKED VOID __stdcall AIL_register_stream_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_stream_callback
}
NAKED VOID __stdcall AIL_auto_service_stream(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_auto_service_stream
}
NAKED VOID __stdcall AIL_set_stream_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_user_data
}
NAKED VOID __stdcall AIL_stream_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_user_data
}
NAKED VOID __stdcall AIL_DLS_open(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_open
}
NAKED VOID __stdcall AIL_DLS_close(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_close
}
NAKED VOID __stdcall AIL_DLS_load_file(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_load_file
}
NAKED VOID __stdcall AIL_DLS_load_memory(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_load_memory
}
NAKED VOID __stdcall AIL_DLS_unload(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_unload
}
NAKED VOID __stdcall AIL_DLS_compact(BYTE)
{
	__asm JMP lpfn_AIL_DLS_compact
}
NAKED VOID __stdcall AIL_DLS_set_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_set_reverb_levels
}
NAKED VOID __stdcall AIL_DLS_get_reverb_levels(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_get_reverb_levels
}
NAKED VOID __stdcall AIL_DLS_get_info(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_DLS_get_info
}
NAKED VOID __stdcall AIL_set_sequence_ms_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sequence_ms_position
}
NAKED VOID __stdcall AIL_sequence_ms_position(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sequence_ms_position
}
NAKED VOID __stdcall AIL_sample_ms_position(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_sample_ms_position
}
NAKED VOID __stdcall AIL_set_sample_ms_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_sample_ms_position
}
NAKED VOID __stdcall AIL_stream_ms_position(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_stream_ms_position
}
NAKED VOID __stdcall AIL_set_stream_ms_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_stream_ms_position
}
NAKED VOID __stdcall AIL_quick_set_ms_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_quick_set_ms_position
}
NAKED VOID __stdcall AIL_quick_ms_position(BYTE)
{
	__asm JMP lpfn_AIL_quick_ms_position
}
NAKED VOID __stdcall AIL_quick_ms_length(BYTE)
{
	__asm JMP lpfn_AIL_quick_ms_length
}
NAKED VOID __stdcall AIL_quick_type(BYTE)
{
	__asm JMP lpfn_AIL_quick_type
}
NAKED VOID __stdcall AIL_MIDI_to_XMI(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_MIDI_to_XMI
}
NAKED VOID __stdcall AIL_compress_ADPCM(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_compress_ADPCM
}
NAKED VOID __stdcall AIL_decompress_ADPCM(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_decompress_ADPCM
}
NAKED VOID __stdcall AIL_WAV_info(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_WAV_info
}
NAKED VOID __stdcall AIL_file_type(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_file_type
}
NAKED VOID __stdcall AIL_find_DLS(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_find_DLS
}
NAKED VOID __stdcall AIL_extract_DLS(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_extract_DLS
}
NAKED VOID __stdcall AIL_primary_digital_driver(BYTE)
{
	__asm JMP lpfn_AIL_primary_digital_driver
}
NAKED VOID __stdcall AIL_enumerate_filters(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_filters
}
NAKED VOID __stdcall AIL_open_filter(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_open_filter
}
NAKED VOID __stdcall AIL_close_filter(BYTE)
{
	__asm JMP lpfn_AIL_close_filter
}
NAKED VOID __stdcall AIL_enumerate_filter_attributes(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_filter_attributes
}
NAKED VOID _AIL_enumerate_filter_sample_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_filter_sample_attribute
}
NAKED VOID __stdcall AIL_filter_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_attribute
}
NAKED VOID __stdcall AIL_filter_sample_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_sample_attribute
}
NAKED VOID __stdcall AIL_filter_stream_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_stream_attribute
}
NAKED VOID __stdcall AIL_filter_DLS_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_DLS_attribute
}
NAKED VOID __stdcall AIL_set_filter_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_filter_preference
}
NAKED VOID __stdcall AIL_set_filter_sample_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_filter_sample_preference
}
NAKED VOID __stdcall AIL_set_filter_stream_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_filter_stream_preference
}
NAKED VOID __stdcall AIL_set_filter_DLS_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_filter_DLS_preference
}
NAKED VOID __stdcall AIL_enumerate_3D_providers(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_3D_providers
}
NAKED VOID __stdcall AIL_open_3D_provider(BYTE)
{
	__asm JMP lpfn_AIL_open_3D_provider
}
NAKED VOID __stdcall AIL_close_3D_provider(BYTE)
{
	__asm JMP lpfn_AIL_close_3D_provider
}
NAKED VOID __stdcall AIL_enumerate_3D_provider_attributes(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_3D_provider_attributes
}
NAKED VOID __stdcall AIL_enumerate_3D_sample_attributes(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_enumerate_3D_sample_attributes
}
NAKED VOID __stdcall AIL_3D_provider_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_provider_attribute
}
NAKED VOID __stdcall AIL_3D_sample_attribute(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_attribute
}
NAKED VOID __stdcall AIL_set_3D_provider_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_provider_preference
}
NAKED VOID __stdcall AIL_set_3D_sample_preference(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_preference
}
NAKED VOID __stdcall AIL_allocate_3D_sample_handle(BYTE)
{
	__asm JMP lpfn_AIL_allocate_3D_sample_handle
}
NAKED VOID __stdcall AIL_release_3D_sample_handle(BYTE)
{
	__asm JMP lpfn_AIL_release_3D_sample_handle
}
NAKED VOID __stdcall AIL_start_3D_sample(BYTE)
{
	__asm JMP lpfn_AIL_start_3D_sample
}
NAKED VOID __stdcall AIL_stop_3D_sample(BYTE)
{
	__asm JMP lpfn_AIL_stop_3D_sample
}
NAKED VOID __stdcall AIL_resume_3D_sample(BYTE)
{
	__asm JMP lpfn_AIL_resume_3D_sample
}
NAKED VOID __stdcall AIL_end_3D_sample(BYTE)
{
	__asm JMP lpfn_AIL_end_3D_sample
}
NAKED VOID __stdcall AIL_set_3D_sample_info(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_info
}
NAKED VOID __stdcall AIL_set_3D_sample_file(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_file
}
NAKED VOID __stdcall AIL_set_3D_sample_volume(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_volume
}
NAKED VOID __stdcall AIL_set_3D_sample_playback_rate(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_playback_rate
}
NAKED VOID __stdcall AIL_set_3D_sample_offset(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_offset
}
NAKED VOID __stdcall AIL_set_3D_sample_loop_count(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_loop_count
}
NAKED VOID __stdcall AIL_set_3D_sample_loop_block(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_loop_block
}
NAKED VOID __stdcall AIL_set_3D_sample_obstruction(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_obstruction
}
NAKED VOID __stdcall AIL_set_3D_sample_exclusion(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_exclusion
}
NAKED VOID __stdcall AIL_set_3D_sample_occlusion(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_occlusion
}
NAKED VOID __stdcall AIL_set_3D_sample_cone(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_cone
}
NAKED VOID __stdcall AIL_set_3D_sample_effects_level(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_effects_level
}
NAKED VOID __stdcall AIL_register_3D_EOS_callback(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_register_3D_EOS_callback
}
NAKED VOID __stdcall AIL_3D_sample_obstruction(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_obstruction
}
NAKED VOID __stdcall AIL_3D_sample_exclusion(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_exclusion
}
NAKED VOID __stdcall AIL_3D_sample_occlusion(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_occlusion
}
NAKED VOID __stdcall AIL_3D_sample_cone(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_cone
}
NAKED VOID __stdcall AIL_3D_sample_effects_level(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_effects_level
}
NAKED VOID __stdcall AIL_3D_sample_status(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_status
}
NAKED VOID __stdcall AIL_3D_sample_volume(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_volume
}
NAKED VOID __stdcall AIL_3D_sample_playback_rate(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_playback_rate
}
NAKED VOID __stdcall AIL_3D_sample_offset(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_offset
}
NAKED VOID __stdcall AIL_3D_sample_length(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_length
}
NAKED VOID __stdcall AIL_3D_sample_loop_count(BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_loop_count
}
NAKED VOID __stdcall AIL_set_3D_sample_distances(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_sample_distances
}
NAKED VOID __stdcall AIL_3D_sample_distances(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_sample_distances
}
NAKED VOID __stdcall AIL_set_3D_user_data(BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_user_data
}
NAKED VOID __stdcall AIL_3D_user_data(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_user_data
}
NAKED VOID __stdcall AIL_active_3D_sample_count(BYTE)
{
	__asm JMP lpfn_AIL_active_3D_sample_count
}
NAKED VOID __stdcall AIL_3D_room_type(BYTE)
{
	__asm JMP lpfn_AIL_3D_room_type
}
NAKED VOID __stdcall AIL_set_3D_room_type(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_room_type
}
NAKED VOID __stdcall AIL_3D_speaker_type(BYTE)
{
	__asm JMP lpfn_AIL_3D_speaker_type
}
NAKED VOID __stdcall AIL_set_3D_speaker_type(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_speaker_type
}
NAKED VOID __stdcall AIL_3D_rolloff_factor(BYTE)
{
	__asm JMP lpfn_AIL_3D_rolloff_factor
}
NAKED VOID __stdcall AIL_set_3D_rolloff_factor(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_rolloff_factor
}
NAKED VOID __stdcall AIL_3D_doppler_factor(BYTE)
{
	__asm JMP lpfn_AIL_3D_doppler_factor
}
NAKED VOID __stdcall AIL_set_3D_doppler_factor(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_doppler_factor
}
NAKED VOID __stdcall AIL_3D_distance_factor(BYTE)
{
	__asm JMP lpfn_AIL_3D_distance_factor
}
NAKED VOID __stdcall AIL_set_3D_distance_factor(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_distance_factor
}
NAKED VOID __stdcall AIL_open_3D_listener(BYTE)
{
	__asm JMP lpfn_AIL_open_3D_listener
}
NAKED VOID __stdcall AIL_close_3D_listener(BYTE)
{
	__asm JMP lpfn_AIL_close_3D_listener
}
NAKED VOID __stdcall AIL_open_3D_object(BYTE)
{
	__asm JMP lpfn_AIL_open_3D_object
}
NAKED VOID __stdcall AIL_close_3D_object(BYTE)
{
	__asm JMP lpfn_AIL_close_3D_object
}
NAKED VOID __stdcall AIL_set_3D_position(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_position
}
NAKED VOID __stdcall AIL_set_3D_velocity(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_velocity
}
NAKED VOID __stdcall AIL_set_3D_velocity_vector(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_velocity_vector
}
NAKED VOID __stdcall AIL_set_3D_orientation(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_set_3D_orientation
}
NAKED VOID __stdcall AIL_3D_position(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_position
}
NAKED VOID __stdcall AIL_3D_velocity(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_velocity
}
NAKED VOID __stdcall AIL_3D_orientation(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_3D_orientation
}
NAKED VOID __stdcall AIL_update_3D_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_update_3D_position
}
NAKED VOID __stdcall AIL_auto_update_3D_position(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_auto_update_3D_position
}
NAKED VOID __stdcall AIL_size_processed_digital_audio(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_size_processed_digital_audio
}
NAKED VOID __stdcall AIL_process_digital_audio(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_process_digital_audio
}
NAKED VOID __stdcall AIL_merge_DLS_with_XMI(BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_merge_DLS_with_XMI
}
NAKED VOID __stdcall AIL_compress_DLS(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_compress_DLS
}
NAKED VOID __stdcall AIL_filter_DLS_with_XMI(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_filter_DLS_with_XMI
}
NAKED VOID __stdcall AIL_compress_ASI(BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_compress_ASI
}
NAKED VOID __stdcall AIL_decompress_ASI(BYTE, BYTE, BYTE, BYTE, BYTE, BYTE)
{
	__asm JMP lpfn_AIL_decompress_ASI
}
NAKED VOID __stdcall AIL_request_EOB_ASI_reset(BYTE, BYTE)
{
	__asm JMP lpfn_AIL_request_EOB_ASI_reset
}
NAKED VOID __stdcall AIL_set_redist_directory(BYTE)
{
	__asm JMP lpfn_AIL_set_redist_directory
}
NAKED VOID __stdcall MIX_RIB_MAIN(BYTE, BYTE)
{
	__asm JMP lpfn_MIX_RIB_MAIN
}
NAKED VOID __stdcall AIL_mem_use_malloc(BYTE)
{
	__asm JMP lpfn_AIL_mem_use_malloc
}
NAKED VOID __stdcall AIL_mem_use_free(BYTE)
{
	__asm JMP lpfn_AIL_mem_use_free
}
NAKED VOID AIL_sprintf(VOID)
{
	__asm JMP lpfnAIL_sprintf
}
NAKED VOID DLSMSSOpen(VOID)
{
	__asm JMP lpfnDLSMSSOpen
}
NAKED VOID DLSClose(VOID)
{
	__asm JMP lpfnDLSClose
}
NAKED VOID DLSLoadFile(VOID)
{
	__asm JMP lpfnDLSLoadFile
}
NAKED VOID DLSLoadMemFile(VOID)
{
	__asm JMP lpfnDLSLoadMemFile
}
NAKED VOID DLSGetInfo(VOID)
{
	__asm JMP lpfnDLSGetInfo
}
NAKED VOID DLSCompactMemory(VOID)
{
	__asm JMP lpfnDLSCompactMemory
}
NAKED VOID DLSUnloadAll(VOID)
{
	__asm JMP lpfnDLSUnloadAll
}
NAKED VOID DLSUnloadFile(VOID)
{
	__asm JMP lpfnDLSUnloadFile
}
NAKED VOID DLSSetAttribute(VOID)
{
	__asm JMP lpfnDLSSetAttribute
}
NAKED VOID __stdcall DLSMSSGetCPU(BYTE)
{
	__asm JMP lpfn_DLSMSSGetCPU
}

//-------------------------------------------
// IJL.dll exports

//NAKED void ijlGetLibVersion()
//{
//	__asm	jmp lpfnIJLGetLibVersion
//}
//
//NAKED void ijlInit()
//{
//	__asm	jmp lpfnIJLInit
//}
//
//NAKED void ijlFree()
//{
//	__asm	jmp lpfnIJLFree
//}
//
//NAKED void ijlRead()
//{
//	__asm	jmp lpfnIJLRead
//}
//
//NAKED void ijlWrite()
//{
//	__asm {
//		PUSH	EBP
//		MOV		EBP, ESP
//		MOV		EAX, DWORD PTR SS:[EBP+8h]
//		MOV		ECX, ssQuality
//		MOV		DWORD PTR DS:[EAX+50h], ECX
//		MOV		EDX, DWORD PTR SS:[EBP+0Ch]
//		PUSH	EDX
//		MOV		EAX, DWORD PTR SS:[EBP+08h]
//		PUSH	EAX
//		CALL	lpfnIJLWrite
//		POP		EBP
//		RETN
//	}
//}
//
//NAKED void ijlErrorStr()
//{
//	__asm	jmp lpfnIJLErrorStr
//}