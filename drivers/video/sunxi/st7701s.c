#include <errno.h>
#include <common.h>
#include <malloc.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <stdlib.h>
#include <power/battery.h>
#include <linux/delay.h>
#include "st7701s.h"

DECLARE_GLOBAL_DATA_PTR;

#define COMPAT_LCD_ili9806  "spi_st7701s"
#define STATUS_ON 1
#define STATUS_OFF 0

#define set_spi_ili9806_high(x)     gpio_direction_output(x, STATUS_ON)
#define set_spi_ili9806_low(x)      gpio_direction_output(x, STATUS_OFF)

struct ili9806_reg {
    u8 comm;
    u8 val[150];
};


struct ili9806_info {
    int node;
    int dts_cs;
    int dts_clk;
    int dts_data;
    int dts_reset;
    struct ili9806_reg *reg;
};


static struct ili9806_info hi;

extern int __fdtdec_decode_gpio(const void *blob, int node, const char *prop_name,
        struct fdt_gpio_state *child, int mode);

static struct ili9806_reg ili9806_data[] = {
	{
	.comm = 0xFF,
    .val = {0x77,0x01,0x00,0x00,0x10}
    },{
    .comm = 0xC0,
    .val = {0x63,0x00}
    },{
    .comm = 0xC1,
    .val = {0x11,0x02}
    },{
    .comm = 0xC2,
    .val = {0x31,0x08}
    },{
    .comm = 0xC3,
    .val = {0x10}
    },{
    .comm = 0xCC,
    .val = {0x10}
    },{
    .comm = 0xB0,
    .val = {0x40,0x01,0x46,0x0D,0x13,0x09,0x05,0x09,0x09,0x1B,0x07,0x15,0x12,0x4C,0x10,0xC8}
    },{
    .comm = 0xB1,
    .val = {0x40,0x02,0x86,0x0D,0x13,0x09,0x05,0x09,0x09,0x1F,0x07,0x15,0x12,0x15,0x19,0x08}
    },{
    .comm = 0xFF,
    .val = {0x77,0x01,0x00,0x00,0x11}
    },{
    .comm = 0xB0,
    .val = {0x50}
    },{
    .comm = 0xB1,
    .val = {0x68}
    },{
    .comm = 0xB2,
    .val = {0x07}
    },{
    .comm = 0xB3,
    .val = {0x80}
    },{
    .comm = 0xB5,
    .val = {0x47}
    },{
    .comm = 0xB7,
    .val = {0x85}
    },{
    .comm = 0xB8,
    .val = {0x21}
    },{
    .comm = 0xB9,
    .val = {0x10}
    },{
    .comm = 0xC1,
    .val = {0x78}
    },{
    .comm = 0xC2,
    .val = {0x78}
    },{
    .comm = 0xD0,
    .val = {0x88}
    },{
    .comm = 0xE0,
    .val = {0x00,0x00,0x02}
    },{
    .comm = 0xE1,
    .val = {0x08,0x00,0x0A,0x00,0x07,0x00,0x09,0x00,0x00,0x33,0x33}
    },{
    .comm = 0xE2,
    .val = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
    },{
    .comm = 0xE3,
    .val = {0x00,0x00,0x33,0x33}
    },{
    .comm = 0xE4,
    .val = {0x44,0x44}
    },{
    .comm = 0xE5,
    .val = {0x0E,0x2D,0xA0,0xA0,0x10,0x2D,0xA0,0xA0,0x0A,0x2D,0xA0,0xA0,0x0C,0x2D,0xA0,0xA0}
    },{
    .comm = 0xE6,
    .val = {0x00,0x00,0x33,0x33}
    },{
    .comm = 0xE7,
    .val = {0x44,0x44}
    },{
    .comm = 0xE8,
    .val = {0x0D,0x2D,0xA0,0xA0,0x0F,0x2D,0xA0,0xA0,0x09,0x2D,0xA0,0xA0,0x0B,0x2D,0xA0,0xA0}
    },{
    .comm = 0xEB,
    .val = {0x02,0x01,0xE4,0xE4,0x44,0x00,0x40}
    },{
    .comm = 0xEC,
    .val = {0x02,0x01}
    },{
    .comm = 0xED,
    .val = {0xAB,0x89,0x76,0x54,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x45,0x67,0x98,0xBA}
    },{
    .comm = 0xFF,
    .val = {0x77,0x01,0x00,0x00,0x00}
	},{
	.comm =0x3A,
    .val = {0x66}
    }
};
#if 0
static struct ili9806_reg ili9806_data[] = {
    //bank 0
    {
    .comm = 0xFF,
    .val = {0x77,0x01,0x00,0x00,0x10}
    },{
    .comm = 0xC0,
    .val = {0x63,0x00}
    },{
    //vbp=10 vfp=2
    .comm = 0xC1,
    .val = {0x0A,0x02}
    },{
    .comm = 0xC2,
    .val = {0x31,0x08}
    },/*{
    // de mode
    .comm = 0xC3,
    .val = {0x0C}
    },*/{
    .comm = 0xCC,
    .val = {0x10} 
    },{
    .comm = 0xB0,
    .val = {0x00,0x11,0x19,0x0C,0x10,0x06,0x07,0x0A,0x09,0x22,0x04,0x10,0x0E,0x28,0x30,0x1C}
    },{
    .comm = 0xB1,
    .val = {0x00,0x12,0x19,0x0D,0x10,0x04,0x06,0x07,0x08,0x23,0x04,0x12,0x11,0x28,0x30,0x1C}
    },
    //bank1
    {
    .comm = 0xFF,
    .val = {0x77,0x01,0x00,0x00,0x11}
    },{
    .comm = 0xB0,
    .val = {0x4D}
    },{
    .comm = 0xB1,
    .val = {0x3E}
    },{
    .comm = 0xB2,
    .val = {0x07}
    },{
    .comm = 0xB3,
    .val = {0x80}
    },{
    .comm = 0xB5,
    .val = {0x47}
    },{
    .comm = 0xB7,
    .val = {0x85}
    },{
    .comm = 0xB8,
    .val = {0x21}
    },{
    .comm = 0xB9,
    .val = {0x10}
    },{
    .comm = 0xC1,
    .val = {0x78}
    },{
    .comm = 0xC2,
    .val = {0x78}
    },{
    .comm = 0xD0,
    .val = {0x88}
    },{
    .comm = 0xE0,
    .val = {0x00,0x00,0x02}
    },{
    .comm = 0xE1,
    .val = {0x04,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x20,0x20}
    },{
    .comm = 0xE2,
    .val = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
    },{
    .comm = 0xE3,
    .val = {0x00,0x00,0x33,0x00}
    },{
    .comm = 0xE4,
    .val = {0x22,0x00}
    },{
    .comm = 0xE5,
    .val = {0x04,0x34,0xAA,0xAA,0x06,0x34,0xAA,0xAA,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
    },{
    .comm = 0xE6,
    .val = {0x00,0x00,0x33,0x00}
    },{
    .comm = 0xE7,
    .val = {0x22,0x00}
    },{
    .comm = 0xE8,
    .val = {0x05,0x34,0xAA,0xAA,0x07,0x34,0xAA,0xAA,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
    },{
    .comm = 0xEB,
    .val = {0x02,0x00,0x40,0x40,0x00,0x00,0x00}
    },{
    .comm = 0xEC,
    .val = {0x00,0x00}
    },{
    .comm = 0xED,
    .val = {0xFA,0x45,0x0B,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xB0,0x54,0xAF}
    },{
    .comm = 0xFF,
    .val = {0x77,0x01,0x00,0x00,0x00}
    },{
    .comm = 0x3A,
    .val = {0x66}
    },{
    .comm = 0x36,
    .val = {0x08}
    }/*,{
    .comm = 0xFF,
    .val = {0x77,0x01,0x00,0x00,0x12}
    },{
    .comm = 0xD1,
    .val = {0x81,0x08,0x03,0x20,0x08,0x01,0xA0,0x01,0xE0,0xA0,0x01,0xE0,0x03,0x20}
    },{
    .comm = 0xD2,
    .val = {0x08}
    }*/
};
#endif

static void ili9806_SendData(unsigned char i)
{
    unsigned char n;
    for(n = 0; n < 8; n++) {
        if(i & 0x80) {
            set_spi_ili9806_high(hi.dts_data);
        } else {
            set_spi_ili9806_low(hi.dts_data);
        }
        
        i <<= 1;
     
        set_spi_ili9806_low(hi.dts_clk);
        udelay(1);
        set_spi_ili9806_high(hi.dts_clk);
        udelay(1);
    }
}


static void ili9806_WriteCommand(unsigned char i)
{
    set_spi_ili9806_low(hi.dts_cs);
    set_spi_ili9806_low(hi.dts_data);

    set_spi_ili9806_low(hi.dts_clk);
    udelay(1);
    set_spi_ili9806_high(hi.dts_clk);
    udelay(1);
    
    ili9806_SendData(i);

    set_spi_ili9806_high(hi.dts_cs);
}


static void ili9806_WriteData(unsigned char i)
{
    set_spi_ili9806_low(hi.dts_cs);

    set_spi_ili9806_high(hi.dts_data);

    set_spi_ili9806_low(hi.dts_clk);
    udelay(1);
    set_spi_ili9806_high(hi.dts_clk);
    udelay(1);
    
    ili9806_SendData(i);
    
    set_spi_ili9806_high(hi.dts_cs);
}


#define WRITE_ARRY ili9806_data
#define LEN_ARRAY(x, y) sizeof(x) / sizeof(y)
void spi_lcd_ili9806_config(void)
{
    int row;
    int column;
    //reset 
    set_spi_ili9806_low(hi.dts_reset);
    mdelay(10);
    set_spi_ili9806_high(hi.dts_reset);
    mdelay(120);

    ili9806_WriteCommand(0x11);
    mdelay(120);
    for (row = 0; row < LEN_ARRAY(WRITE_ARRY, struct ili9806_reg); ++row) {
        //printf("INFO: comm[%d] is = 0x%x \n", row, WRITE_ARRY[row].comm);
        ili9806_WriteCommand(WRITE_ARRY[row].comm);
        
        for (column = 0; column < LEN_ARRAY(WRITE_ARRY[row].val, __u8); ++column) {
            if (WRITE_ARRY[row].comm == WRITE_ARRY[row].val[column]) {

                //if (WRITE_ARRY[row].val[column] == 0xB9) {
                    //printf("Now Delay 10 ms!\n");
                    //mdelay(10);
                //}
                
                //printf("INFO: comm[%d] over! \n", row);
                break;
            }
            
            //printf("\t comm[%d], val[%d] is = 0x%x \n", row, column, WRITE_ARRY[row].val[column]);    
            ili9806_WriteData(WRITE_ARRY[row].val[column]);
            
        }
        //printf("\n");
    }

    
    ili9806_WriteCommand(0x29);
    udelay(50);
    //ili9806_WriteCommand(0x2c);
    
}


static int spi_lcd_ili9806_parse_dt()
{
    // hi.node = fdt_node_offset_by_compatible(blob, 0, COMPAT_LCD_ili9806);
    // if (hi.node < 0) {
    //     printf("can't find dts node for ili9806\n");
    //     return -ENODEV;
    // }

    // if (!fdt_device_is_available(blob, hi.node)) {
    //     printf("ili9806 is disabled!\n");
    //     return -EPERM;
    // }
    hi.dts_cs = sunxi_name_to_gpio(CONFIG_VIDEO_ST7701_CS);
	if (hi.dts_cs >= 0) {
		gpio_request(hi.dts_cs, "lcd_st7701_cs");
		gpio_direction_output(hi.dts_cs, 1);
	}

    hi.dts_clk = sunxi_name_to_gpio(CONFIG_VIDEO_ST7701_CLK);
	if (hi.dts_clk >= 0) {
		gpio_request(hi.dts_clk, "lcd_st7701_clk");
		gpio_direction_output(hi.dts_clk, 1);
	}

    hi.dts_data = sunxi_name_to_gpio(CONFIG_VIDEO_ST7701_DATA);
	if (hi.dts_data >= 0) {
		gpio_request(hi.dts_data, "lcd_st7701_data");
		gpio_direction_output(hi.dts_data, 1);
	}

    hi.dts_reset = sunxi_name_to_gpio(CONFIG_VIDEO_ST7701_RESET);
	if (hi.dts_reset >= 0) {
		gpio_request(hi.dts_reset, "lcd_st7701_reset");
		gpio_direction_output(hi.dts_reset, 1);
	}

    /* Initialize spi gpios, cs:high clk:low data:low */
    set_spi_ili9806_high(hi.dts_cs);
    set_spi_ili9806_high(hi.dts_clk);
    set_spi_ili9806_high(hi.dts_data);
    set_spi_ili9806_high(hi.dts_reset);
    return 0;
}



int spi_lcd_ili9806_init(void)
{
    int ret;
    printf("spi lcd ili9806 parse dt start\n");

    ret = spi_lcd_ili9806_parse_dt();
    if (ret < 0) {
        printf("lcd ili9806 parse dt failed!\n");
        return ret;
    }

    printf("lcd ili9806 parse dt successfully!\n");

    hi.reg = &ili9806_data[0];

    spi_lcd_ili9806_config();

    printf("lcd ili9806 init over!\n");

    return 0;
}

