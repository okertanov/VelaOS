//
// timer.c -- Initialises the PIT, and handles clock updates.
//            Written for JamesM's kernel development tutorials.
//

#include "timer.h"
#include "kernel.h"
#include "io.h"
#include "idt.h"

/* XXX: For debug only */
#include "video.h"
#include "util.h"

static uint32_t timer_tick_count = 0;

static void timer_irq0_handler(__attribute__((unused)) registers_t *regs)
{
    timer_tick_count++;

    /* XXX: For debug only */
    char buffer[32] = {0};
    txt_write_to_screens(itoa(timer_tick_count, buffer, 10), 1, 22, 0x0A);

    /* For debug only */
    if ( timer_tick_count > 1000 )
    {
        timer_tick_count = 0;
        hw_reboot();
    }
}

void sys_init_timer(void)
{
    register_interrupt_handler(IRQ0, &timer_irq0_handler);

    static const uint32_t frequency = 20;
    uint32_t divisor = 1193180 / frequency;
    uint8_t lo = (uint8_t)(divisor & 0xFF);
    uint8_t hi = (uint8_t)((divisor >> 8) & 0xFF );

    sys_outb(0x43, 0x36);
    sys_outb(0x40, lo);
    sys_outb(0x40, hi);
}

