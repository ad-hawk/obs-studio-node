// Client module for the OBS Studio node module.
// Copyright(C) 2017 Streamlabs (General Workings Inc)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110 - 1301, USA.

#pragma once
#include <ipc-server.hpp>
#include <obs.h>
#include "utility.hpp"

namespace osn
{
	class Module
	{
		public:
		static void Reigster(ipc::server&);

		public:
		class Manager : public utility::unique_object_manager<obs_module_t>
		{
			friend class std::shared_ptr<Manager>;

			protected:
			Manager() {}
			~Manager() {}

			public:
			Manager(Manager const&) = delete;
			Manager operator=(Manager const&) = delete;

			public:
			static Manager& GetInstance();
		};


		// Functions
		static void
		            Open(void* data, const int64_t id, const std::vector<ipc::value>& args, std::vector<ipc::value>& rval);
		static void Initialize(
		    void*                          data,
		    const int64_t                  id,
		    const std::vector<ipc::value>& args,
		    std::vector<ipc::value>&       rval);

		// Methods
		static void
		            GetName(void* data, const int64_t id, const std::vector<ipc::value>& args, std::vector<ipc::value>& rval);
		static void GetFileName(
		    void*                          data,
		    const int64_t                  id,
		    const std::vector<ipc::value>& args,
		    std::vector<ipc::value>&       rval);
		static void
		    GetAuthor(void* data, const int64_t id, const std::vector<ipc::value>& args, std::vector<ipc::value>& rval);
		static void GetDescription(
		    void*                          data,
		    const int64_t                  id,
		    const std::vector<ipc::value>& args,
		    std::vector<ipc::value>&       rval);
		static void GetBinaryPath(
		    void*                          data,
		    const int64_t                  id,
		    const std::vector<ipc::value>& args,
		    std::vector<ipc::value>&       rval);
		static void GetDataPath(
		    void*                          data,
		    const int64_t                  id,
		    const std::vector<ipc::value>& args,
		    std::vector<ipc::value>&       rval);
		static void GetFilePath(
		    void*                          data,
		    const int64_t                  id,
		    const std::vector<ipc::value>& args,
		    std::vector<ipc::value>&       rval);
		static void GetConfigFilePath(
		    void*                          data,
		    const int64_t                  id,
		    const std::vector<ipc::value>& args,
		    std::vector<ipc::value>&       rval);
	};
}