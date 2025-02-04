/*
 * Deskflow -- mouse and keyboard sharing utility
 * Copyright (C) 2013-2016 Symless Ltd.
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

#include "base/Stopwatch.h"
#include "common/stdvector.h"
#include "server/ClientProxy1_4.h"

class Server;
class IEventQueue;

//! Proxy for client implementing protocol version 1.5
class ClientProxy1_5 : public ClientProxy1_4
{
public:
  ClientProxy1_5(const std::string &name, deskflow::IStream *adoptedStream, Server *server, IEventQueue *events);
  ClientProxy1_5(ClientProxy1_5 const &) = delete;
  ClientProxy1_5(ClientProxy1_5 &&) = delete;
  ~ClientProxy1_5();

  ClientProxy1_5 &operator=(ClientProxy1_5 const &) = delete;
  ClientProxy1_5 &operator=(ClientProxy1_5 &&) = delete;

  virtual void sendDragInfo(uint32_t fileCount, const char *info, size_t size);
  virtual void fileChunkSending(uint8_t mark, char *data, size_t dataSize);
  virtual bool parseMessage(const uint8_t *code);
  void fileChunkReceived();
  void dragInfoReceived();

private:
  IEventQueue *m_events;
};
