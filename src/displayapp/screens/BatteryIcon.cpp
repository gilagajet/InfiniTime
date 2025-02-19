#include "displayapp/screens/BatteryIcon.h"
#include <cstdint>
#include "displayapp/screens/Symbols.h"
#include "displayapp/icons/battery/batteryicon.c"

using namespace Pinetime::Applications::Screens;

void BatteryIcon::Create(lv_obj_t* parent) {
  batteryImg = lv_img_create(parent, nullptr);
  lv_img_set_src(batteryImg, &batteryicon);
  lv_obj_set_style_local_image_recolor(batteryImg, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);


  batteryJuice = lv_obj_create(batteryImg, nullptr);
  lv_obj_set_width(batteryJuice, 8);
  lv_obj_align(batteryJuice, nullptr, LV_ALIGN_IN_BOTTOM_RIGHT, -2, -2);
  lv_obj_set_style_local_radius(batteryJuice, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
}

lv_obj_t* BatteryIcon::GetObject() {
  return batteryImg;
}

void BatteryIcon::SetBatteryPercentage(uint8_t percentage) {
  lv_obj_set_height(batteryJuice, percentage * 14 / 100);
  if (percentage <= 40) {
    lv_obj_set_style_local_bg_color(batteryJuice, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0xFF0000));
  } else if (percentage > 40 && percentage < 60) {
    lv_obj_set_style_local_bg_color(batteryJuice, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0xFF8600));
  } else if (percentage >= 60) {
    lv_obj_set_style_local_bg_color(batteryJuice, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x24FF00));
  }
  lv_obj_realign(batteryJuice);

}

void BatteryIcon::SetColor(lv_color_t color) {
  lv_obj_set_style_local_image_recolor(batteryImg, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, color);
  lv_obj_set_style_local_image_recolor_opa(batteryImg, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
  lv_obj_set_style_local_bg_color(batteryJuice, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, color);
}

const char* BatteryIcon::GetPlugIcon(bool isCharging) {
  if (isCharging)
    return Symbols::plug;
  else
    return "";
}
