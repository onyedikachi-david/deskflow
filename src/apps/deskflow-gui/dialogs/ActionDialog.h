/*
 * Deskflow -- mouse and keyboard sharing utility
 * Copyright (C) 2025 Chris Rizzitello <sithlord48@gmail.com>
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2008 Volker Lanz (vl@fidra.de)
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QDialog>

class Hotkey;
class Action;
class ServerConfig;
class KeySequenceWidget;

namespace Ui {
class ActionDialog;
}

class ActionDialog : public QDialog
{
  Q_OBJECT

public:
  enum ActionTypes
  {
    PressKey,
    ReleaseKey,
    ToggleKey,
    SwitchTo,
    SwitchInDirection,
    ModifyCursorLock,
    RestartServer
  };

  ActionDialog(QWidget *parent, const ServerConfig &config, Hotkey &hotkey, Action &action);
  ~ActionDialog() override;

protected slots:
  void accept() override;

private:
  void updateSize();
  void keySequenceChanged();
  void actionTypeChanged(int index);
  bool isKeyAction(int index);
  bool canSave();

  std::unique_ptr<Ui::ActionDialog> ui;
  Hotkey &m_hotkey;
  Action &m_action;
};
