/*
 * Copyright (C) 2013 Graeme Gott <graeme@gottcode.org>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WHISKERMENU_PAGE_H
#define WHISKERMENU_PAGE_H

#include <gtk/gtk.h>

namespace WhiskerMenu
{

class Launcher;
class LauncherView;
class Window;

class Page
{
public:
	explicit Page(WhiskerMenu::Window *window);
	virtual ~Page();

	GtkWidget* get_widget() const
	{
		return m_widget;
	}

	LauncherView* get_view() const
	{
		return m_view;
	}

	void reset_selection();

protected:
	Window* get_window() const
	{
		return m_window;
	}

private:
	virtual bool remember_launcher(Launcher* launcher);
	void launcher_activated(GtkTreeView* view, GtkTreePath* path);
	bool view_button_press_event(GtkWidget* view, GdkEventButton* event);
	bool view_popup_menu_event(GtkWidget* view);
	void on_unmap();
	void destroy_context_menu(GtkMenuShell* menu);
	void add_selected_to_desktop();
	void add_selected_to_panel();
	void add_selected_to_favorites();
	void remove_selected_from_favorites();
	Launcher* get_selected_launcher() const;
	void create_context_menu(GtkTreeIter* iter, GdkEventButton* event);
	virtual void extend_context_menu(GtkWidget* menu);
	static void position_context_menu(GtkMenu*, gint* x, gint* y, gboolean* push_in, Page* page);

private:
	Window* m_window;
	GtkWidget* m_widget;
	LauncherView* m_view;
	GtkTreePath* m_selected_path;


private:
	static void launcher_activated_slot(GtkTreeView* view, GtkTreePath* path, GtkTreeViewColumn*, Page* obj)
	{
		obj->launcher_activated(view, path);
	}

	static gboolean view_button_press_event_slot(GtkWidget* view, GdkEventButton* event, Page* obj)
	{
		return obj->view_button_press_event(view, event);
	}

	static gboolean view_popup_menu_event_slot(GtkWidget* view, Page* obj)
	{
		return obj->view_popup_menu_event(view);
	}

	static void destroy_context_menu_slot(GtkMenuShell* menu, Page* obj)
	{
		obj->destroy_context_menu(menu);
	}

	static void add_selected_to_desktop_slot(GtkMenuItem*, Page* obj)
	{
		obj->add_selected_to_desktop();
	}

	static void add_selected_to_panel_slot(GtkMenuItem*, Page* obj)
	{
		obj->add_selected_to_panel();
	}

	static void add_selected_to_favorites_slot(GtkMenuItem*, Page* obj)
	{
		obj->add_selected_to_favorites();
	}

	static void remove_selected_from_favorites_slot(GtkMenuItem*, Page* obj)
	{
		obj->remove_selected_from_favorites();
	}
};

}

#endif // WHISKERMENU_PAGE_H
