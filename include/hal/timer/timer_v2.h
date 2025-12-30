/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __HAL_TIMER_TIMER_V2_H__
#define __HAL_TIMER_TIMER_V2_H__

#include "hal/pulp.h"
#include "archi/timer/timer_v2.h"

/**
  * hardware provide 2 (apb_)timer
  * timer lo and timer hi
  * both timer can be cascaded to count to 64-bit value
  */
enum timer_id_e
{
  TIMER_LO,
  TIMER_HI
};

typedef    enum timer_id_e    timer_id_t;


#ifdef ARCHI_HAS_FC

static inline unsigned int timer_base_fc(int id, int sub_id)
{
  return ARCHI_FC_TIMER_ADDR + id * ARCHI_FC_TIMER_SIZE + sub_id * 4;
}

#else

#define timer_base_fc(id,sub_id) timer_base_cl(0,id,sub_id)

#endif


#ifdef ARCHI_HAS_CLUSTER

static inline unsigned int timer_base_cl(int cid, int id, int sub_id)
{
  return ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cid) + ARCHI_TIMER_OFFSET + id * ARCHI_TIMER_SIZE + sub_id * 4;
}

#else

static inline unsigned int timer_base_cl(int cid, int id, int sub_id)
{
  return 0;
}


#endif


static inline unsigned int timer_conf_get(unsigned int addr, timer_id_t id)
{
  switch (id)
  {
  case (TIMER_LO):
    /**
      * use cfg get from archi
      * (multiple return is forbidden by MISRA-C?)
      */
    return timer_cfg_lo_get(addr);
    break;
  case (TIMER_HI):
    return timer_cfg_hi_get(addr);
    break;
  }

  /**
    * if @arg id is set properly, this line should never be reached
    * (this break MISRA-C?)
    */
  return 0;
}


static inline void timer_conf_set(unsigned int addr, timer_id_t id, unsigned int value)
{
  switch (id)
  {
  case (TIMER_LO):
    timer_cfg_lo_set(addr, value);
    break;
  case (TIMER_HI):
    timer_cfg_hi_set(addr, value);
    break;

  /* do nothing for invalid id */
  }
}


static inline unsigned int timer_count_get(unsigned int addr, timer_id_t id)
{
  switch (id)
  {
  case (TIMER_LO):
    return timer_cnt_lo_get(addr);
    break;
  case (TIMER_HI):
    return timer_cnt_hi_get(addr);
    break;
  }

  /* invalid case */
  return 0;
}


static inline void timer_count_set(unsigned int addr, timer_id_t id, unsigned int value)
{
  switch (id)
  {
  case (TIMER_LO):
    timer_cnt_lo_set(addr, value);
    break;
  case (TIMER_HI):
    timer_cnt_hi_set(addr, value);
    break;
  }
}


static inline unsigned int timer_cmp_get(unsigned int addr, timer_id_t id)
{
  switch (id)
  {
  case (TIMER_LO):
    return timer_cmp_lo_get(addr);
    break;
  case (TIMER_HI):
    return timer_cmp_hi_get(addr);
    break;
  }

  return 0;
}


static inline void timer_cmp_set(unsigned int addr, timer_id_t id, unsigned int cmp)
{
  switch (id)
  {
  case (TIMER_LO):
    timer_cmp_lo_set(addr, cmp);
    break;
  case (TIMER_HI):
    timer_cmp_hi_set(addr, cmp);
    break;
  }
}


static inline void timer_reset(unsigned int addr, timer_id_t id)
{
  switch (id)
  {
  case (TIMER_LO):
    timer_reset_lo_set(addr, 1);
    break;
  case (TIMER_HI):
    timer_reset_hi_set(addr, 1);
    break;
  }
}


static inline void timer_start(unsigned int addr, timer_id_t id)
{
  switch (id)
  {
  case (TIMER_LO):
    timer_start_lo_set(addr, 1);
    break;
  case (TIMER_HI):
    timer_start_hi_set(addr, 1);
    break;
  }
}


#endif
