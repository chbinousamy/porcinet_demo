//--------------------------------------------------------------------------
// Copyright (C) 2014-2018 Cisco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------
// sid_18758.cc author Russ Combs <rucombs@cisco.com>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <assert.h>
#include <string.h>

#include "main/snort_types.h"
#include "framework/so_rule.h"
#include "sid_18758.h"

using namespace snort;

static IpsOption::EvalStatus eval(void*, Cursor&, Packet*)
{
    return IpsOption::MATCH;
}

static SoEvalFunc ctor(const char* /*so*/, void** pv)
{
    // so == "eval" here because that's our only so: option
    // but we could use multiple so: options and bind to
    // different functions based on the value of so
    // *pv can point to any data we need to use with so
    *pv = nullptr;
    return eval;
}

static void dtor(void* /*pv*/)
{
    // cast pv to your type here
    // and then delete it
}

static const SoApi so_api =
{
    {
        PT_SO_RULE,
        sizeof(SoApi),
        SOAPI_VERSION,
        1,
        API_RESERVED,
        API_OPTIONS,
        "3_18758_8",
        "SO rule example",
        nullptr,
        nullptr
    },
    (uint8_t*)rule_3_18758_8,
    rule_3_18758_8_len,
    nullptr, // pinit
    nullptr, // pterm
    nullptr, // tinit
    nullptr, // tterm
    ctor,
    dtor,
};

// other snort plugins can be put in this list as needed
// eg multiple rules in one so, custom rule options, etc.
SO_PUBLIC const BaseApi* snort_plugins[] =
{
    &so_api.base,
    nullptr
};

