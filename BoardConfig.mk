#
# Copyright (C) 2016 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# inherit from common msm8610-common
-include device/motorola/msm8610-common/BoardConfigCommon.mk

LOCAL_PATH := device/microsoft/chakra

TARGET_KERNEL_SOURCE := kernel/microsoft/linux-next
TARGET_KERNEL_CONFIG := msm8212_defconfig

# Storage & partiiton
BOARD_BOOTIMAGE_PARTITION_SIZE := 10485760
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 10485760
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1895825408
BOARD_USERDATAIMAGE_PARTITION_SIZE := 5418909696
BOARD_CACHEIMAGE_PARTITION_SIZE := 268435456
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_FLASH_BLOCK_SIZE := 131072

TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/ramdisk/fstab.qcom

# Asserts
TARGET_OTA_ASSERT_DEVICE :=  chakra #xt1505,xt1506,otus_umts,otus_umtsds,otus,otus_ds

# Init
TARGET_INIT_VENDOR_LIB := libinit_chakra
TARGET_RECOVERY_DEVICE_MODULES := libinit_chakra

BOARD_SEPOLICY_DIRS += \
    $(LOCAL_PATH)/sepolicy
