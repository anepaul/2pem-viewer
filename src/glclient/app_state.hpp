#ifndef __CLIENT_APP_STATE_HPP__
#define __CLIENT_APP_STATE_HPP__

#include "config.hpp"

#include <boost/optional.hpp>

#include "client_asio_state.hpp"
#if USE_AUDIO_INPUT
#    include "client_audio_input.hpp"
#endif // USE_AUDIO_INPUT
#include "client_input_window.hpp"
#include "client_options.hpp"
#if USE_OSC
#    include "client_osc_state.hpp"
#endif // USE_OSC
#include "client_signal_dispatcher.hpp"
#include "client_slm_state.hpp"
#include "client_slm_window.hpp"
#include "frame.hpp"

struct client_app_state {
    client_app_state(client_options const & options);
    static client_app_state from_cli_args(int argc, char ** argv);
    void run();
private:
    client_options options_;
    client_signal_dispatcher signal_dispatcher_;
    client_asio_state asio_state_;
#if USE_AUDIO_INPUT
    client_audio_input audio_input_;
#endif // USE_AUDIO_INPUT
#if USE_OSC
    client_osc_state osc_state_;
#endif // USE_OSC
    glfw::library library_;
    client_input_window input_window_;
    client_slm_window slm_window_;
    client_slm_state slm_state_;
    frame frame_;
    boost::optional<frame> template_frame_;
};

#endif // __CLIENT_APP_STATE_HPP__

// Local Variables:
// indent-tabs-mode: nil
// End: