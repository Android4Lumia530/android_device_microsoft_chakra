/*
   Copyright (c) 2016, The CyanogenMod Project

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    std::string platform;
    std::string radio;
    std::string device;
    int rc;

    platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    property_override("ro.product.model", "Lumia 535");
    /*radio = property_get("ro.boot.radio");
    if (radio == "0x1") {
        /* xt1505 
        property_override("ro.product.device", "otus");
        property_override("ro.build.product", "otus");
        property_override("ro.build.description", "otus_retuglb-user 5.0.2 LXC22.99-12 11 release-keys");
        property_override("ro.build.fingerprint", "motorola/otus_retuglb/otus:5.0.2/LXC22.99-12/11:user/release-keys");
        property_set("ro.mot.build.customerid", "retusa_glb");
        property_set("ro.telephony.default_network", "0");
        property_set("persist.radio.multisim.config", "");
    }
    else if (radio == "0x5") {
        /* xt1506 
        property_override("ro.product.device", "otus_ds");
        property_override("ro.build.product", "otus_ds");
        property_override("ro.build.description", "otus_reteu_ds-user 5.0.2 LXC22.99-13 11 release-keys");
        property_override("ro.build.fingerprint", "motorola/otus_reteu_ds/otus_ds:5.0.2/LXC22.99-13/11:user/release-keys");
        property_set("ro.mot.build.customerid", "reteuall");
        property_set("ro.telephony.default_network", "0,1");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("persist.radio.plmn_name_cmp", "1");
        property_set("ro.telephony.ril.config", "simactivation,sim2gsmonly");
    }
    else if (radio == "0x6") {
        /* xt1511 
        property_override("ro.product.device", "otus");
        property_override("ro.build.product", "otus");
        property_override("ro.build.description", "otus_retuaws-user 5.0.2 LXC22.99-12 10 release-keys");
        property_override("ro.build.fingerprint", "motorola/otus_retuaws/otus:5.0.2/LXC22.99-12/10:user/release-keys");
        property_set("ro.mot.build.customerid", "retusa_aws");
        property_set("ro.telephony.default_network", "0");
        property_set("persist.radio.multisim.config", "");
    }
    device = property_get("ro.product.device");
    INFO("Found radio id: %s setting build properties for %s device\n", radio.c_str(), device.c_str());*/
}
