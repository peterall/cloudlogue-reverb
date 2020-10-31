/*
 * File: delayline.cpp
 *
 * Test SDRAM memory i/o for delay lines
 *
 * 
 * 
 * 2018 (c) Korg
 *
 */

#include "userrevfx.h"

#include "eurorack/clouds/dsp/frame.h"
#include "eurorack/clouds/dsp/fx/reverb.h"

clouds::Reverb reverb;

static __sdram uint16_t buffer[16384];
static float reverb_amount = 0.f;
static float cutoff = 1.f;

void *__dso_handle;

void REVFX_INIT(uint32_t platform, uint32_t api)
{
  reverb.Init(buffer);
}

void REVFX_PROCESS(float *xn, uint32_t frames)
{
  clouds::FloatFrame *out = reinterpret_cast<clouds::FloatFrame*>(xn);

  reverb.set_amount(reverb_amount * 0.54f);
  reverb.set_diffusion(0.7f);
  reverb.set_time(0.35f + 0.63f * reverb_amount);
  reverb.set_input_gain(0.2f);
  reverb.set_lp(0.6f + 0.37f * cutoff);
  reverb.Process(out, frames);
}

void REVFX_PARAM(uint8_t index, int32_t value)
{
  const float valf = q31_to_f32(value);
  switch (index) {
  case k_user_revfx_param_time:
    cutoff = valf;
    break;
  case k_user_revfx_param_depth:
    reverb_amount = valf;
    break;
  case k_user_revfx_param_shift_depth:
    break;
  default:
    break;
  }
}
