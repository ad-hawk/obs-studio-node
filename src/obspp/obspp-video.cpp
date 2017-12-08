#pragma once

#include "obspp-video.hpp"

namespace obs {

video::video(video_t *video)
 : m_handle(video)
{

}

video::video(video_output_info *info)
{
    m_status = static_cast<video::status_type>(video_output_open(&m_handle, info));
}

video::~video()
{
    
}

video_t *video::dangerous()
{
    return m_handle;
}

void video::close()
{
    video_output_close(m_handle);
}

int video::reset(struct obs_video_info *info)
{
    return obs_reset_video(info);
}

bool video::active()
{
    return video_output_active(m_handle);
}

void video::stop()
{
    video_output_stop(m_handle);
}

bool video::stopped()
{
    return video_output_stopped(m_handle);
}

enum video_format video::format()
{
    return video_output_get_format(m_handle);
}

uint32_t video::height()
{
    return video_output_get_height(m_handle);
}

uint32_t video::width()
{
    return video_output_get_width(m_handle);
}

uint32_t video::frame_rate()
{
    return video_output_get_frame_rate(m_handle);
}

uint32_t video::skipped_frames()
{
    return video_output_get_skipped_frames(m_handle);
}

uint32_t video::total_frames()
{
    return video_output_get_total_frames(m_handle);
}

obs::video video::global()
{
    return obs_get_video();
}

/* Video Encoder */
video_encoder::video_encoder(std::string id, std::string name, obs_data_t *settings, obs_data_t *hotkeys)
 : m_handle(obs_video_encoder_create(id.c_str(), name.c_str(), settings, hotkeys))
{
}

video_encoder::video_encoder(obs_encoder_t *encoder)
 : m_handle(encoder)
{
}

obs_encoder_t *video_encoder::dangerous()
{
    return m_handle;
}

std::vector<std::string> video_encoder::types()
{
    const char *id = nullptr;
    std::vector<std::string> type_list;

    int i = 0;

    while (obs_enum_encoder_types(i++, &id)) {
        if (obs_get_encoder_type(id) != OBS_ENCODER_VIDEO)
            continue;

        type_list.push_back(std::move(std::string(id)));
    }

    return type_list;
}

}