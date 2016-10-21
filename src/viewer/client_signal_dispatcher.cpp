#include "client_signal_dispatcher.hpp"

void
client_signal_dispatcher::left_mouse_down(double xpos, double ypos) const
{
	left_mouse_down_signal_(xpos, ypos);
}

void
client_signal_dispatcher::connect_left_mouse_down_slot(
	std::function<void(double, double)> & cb)
{
	left_mouse_down_signal_.connect(cb);
}

void
client_signal_dispatcher::right_mouse_down(double xpos, double ypos) const
{
	right_mouse_down_signal_(xpos, ypos);
}

void
client_signal_dispatcher::connect_right_mouse_down_slot(
	std::function<void(double, double)> & cb)
{
	right_mouse_down_signal_.connect(cb);
}

void
client_signal_dispatcher::scroll(double xoffset, double yoffset) const
{
	scroll_signal_(xoffset, yoffset);
}

void
client_signal_dispatcher::connect_scroll_slot(
	std::function<void(double, double)> & cb)
{
	scroll_signal_.connect(cb);
}

void
client_signal_dispatcher::key_down(int key, int mods) const
{
	key_down_signal_(key, mods);
}

void
client_signal_dispatcher::connect_key_down_slot(
	std::function<void(int, int)> & cb)
{
	key_down_signal_.connect(cb);
}

void
client_signal_dispatcher::redraw_slm_window(frame const & f) const
{
	redraw_slm_window_signal_(f);
}

void
client_signal_dispatcher::connect_redraw_slm_window_slot(
	std::function<void(frame const &)> & cb)
{
	redraw_slm_window_signal_.connect(cb);
}
