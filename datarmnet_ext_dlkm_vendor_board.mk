#Build rmnet modules
DATA_OFFLOAD_DLKM_BOARD_PLATFORMS_LIST := lahaina
DATA_OFFLOAD_DLKM_BOARD_PLATFORMS_LIST += taro
DATA_SHS_DLKM_BOARD_PLATFORMS_LIST := lahaina
ifneq ($(TARGET_BOARD_AUTO),true)
ifeq ($(call is-board-platform-in-list,$(DATA_OFFLOAD_DLKM_BOARD_PLATFORMS_LIST)),true)
BOARD_VENDOR_KERNEL_MODULES += $(KERNEL_MODULES_OUT)/rmnet_offload.ko
endif
ifeq ($(call is-board-platform-in-list,$(DATA_SHS_DLKM_BOARD_PLATFORMS_LIST)),true)
BOARD_VENDOR_KERNEL_MODULES += $(KERNEL_MODULES_OUT)/rmnet_shs.ko
endif
endif
