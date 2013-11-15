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

#ifndef WHISKERMENU_CONFIGURATION_DIALOG_H
#define WHISKERMENU_CONFIGURATION_DIALOG_H

#include <gtk/gtk.h>

namespace WhiskerMenu
{

class CommandEdit;
class Plugin;

class ConfigurationDialog
{
public:
	explicit ConfigurationDialog(Plugin* plugin);
	~ConfigurationDialog();

	GtkWidget* get_widget() const
	{
		return m_window;
	}

private:
	void toggle_show_name(GtkToggleButton* button);
	void toggle_show_description(GtkToggleButton* button);
	void toggle_position_search_alternate(GtkToggleButton* button);
	void toggle_position_commands_alternate(GtkToggleButton* button);
	void category_icon_size_changed(GtkComboBox* combo);
	void item_icon_size_changed(GtkComboBox* combo);

	void style_changed(GtkComboBox* combo);
	void title_changed();
	void choose_icon();

	void toggle_hover_switch_category(GtkToggleButton* button);
	void toggle_load_hierarchy(GtkToggleButton* button);
	void toggle_remember_favorites(GtkToggleButton* button);
	void toggle_display_recent(GtkToggleButton* button);

	void response(int response_id);
	GtkWidget* init_appearance_tab();
	GtkWidget* init_behavior_tab();
	GtkWidget* init_commands_tab();

private:
	Plugin* m_plugin;
	GtkWidget* m_window;

	GtkWidget* m_show_names;
	GtkWidget* m_show_descriptions;
	GtkWidget* m_position_search_alternate;
	GtkWidget* m_position_commands_alternate;
	GtkWidget* m_category_icon_size;
	GtkWidget* m_item_icon_size;

	GtkWidget* m_button_style;
	GtkWidget* m_title;
	GtkWidget* m_icon;
	GtkWidget* m_icon_button;

	GtkWidget* m_hover_switch_category;
	GtkWidget* m_load_hierarchy;
	GtkWidget* m_remember_favorites;
	GtkWidget* m_display_recent;

	CommandEdit* m_settings_command;
	CommandEdit* m_lockscreen_command;
	CommandEdit* m_switchuser_command;
	CommandEdit* m_logout_command;
	CommandEdit* m_menueditor_command;


private:
	static void choose_icon_slot(GtkButton*, ConfigurationDialog* obj)
	{
		obj->choose_icon();
	}

	static void category_icon_size_changed_slot(GtkComboBox* combo, ConfigurationDialog* obj)
	{
		obj->category_icon_size_changed(combo);
	}

	static void item_icon_size_changed_slot(GtkComboBox* combo, ConfigurationDialog* obj)
	{
		obj->item_icon_size_changed(combo);
	}

	static void style_changed_slot(GtkComboBox* combo, ConfigurationDialog* obj)
	{
		obj->style_changed(combo);
	}

	static void title_changed_slot(GtkEditable*, ConfigurationDialog* obj)
	{
		obj->title_changed();
	}

	static void toggle_hover_switch_category_slot(GtkToggleButton* button, ConfigurationDialog* obj)
	{
		obj->toggle_hover_switch_category(button);
	}

	static void toggle_show_name_slot(GtkToggleButton* button, ConfigurationDialog* obj)
	{
		obj->toggle_show_name(button);
	}

	static void toggle_show_description_slot(GtkToggleButton* button, ConfigurationDialog* obj)
	{
		obj->toggle_show_description(button);
	}

	static void toggle_position_search_alternate_slot(GtkToggleButton* button, ConfigurationDialog* obj)
	{
		obj->toggle_position_search_alternate(button);
	}

	static void toggle_position_commands_alternate_slot(GtkToggleButton* button, ConfigurationDialog* obj)
	{
		obj->toggle_position_commands_alternate(button);
	}

	static void toggle_load_hierarchy_slot(GtkToggleButton* button, ConfigurationDialog* obj)
	{
		obj->toggle_load_hierarchy(button);
	}

	static void toggle_remember_favorites_slot(GtkToggleButton* button, ConfigurationDialog* obj)
	{
		obj->toggle_remember_favorites(button);
	}

	static void toggle_display_recent_slot(GtkToggleButton* button, ConfigurationDialog* obj)
	{
		obj->toggle_display_recent(button);
	}

	static void response_slot(GtkDialog*, gint response_id, ConfigurationDialog* obj)
	{
		obj->response(response_id);
	}
};

}

#endif // WHISKERMENU_CONFIGURATION_DIALOG_H
