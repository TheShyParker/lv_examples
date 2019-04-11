/**
 * @file lv_test_chart.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_test_chart.h"
#include <stdlib.h>

#if LV_USE_BTN && LV_USE_TESTS

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create charts to test their functionalities
 */
void lv_test_chart_1(void)
{
    /* Create a default object*/
    lv_obj_t * chart1 = lv_chart_create(lv_disp_get_scr_act(NULL), NULL);

    lv_chart_series_t * dl1_1 = lv_chart_add_series(chart1, LV_COLOR_RED);
    dl1_1->points[0] = 0;
    dl1_1->points[1] = 25;
    dl1_1->points[2] = 0;
    dl1_1->points[3] = 50;
    dl1_1->points[4] = 0;
    dl1_1->points[5] = 75;
    dl1_1->points[6] = 0;
    dl1_1->points[7] = 100;
    dl1_1->points[8] = 0;

    lv_chart_series_t * dl1_2 = lv_chart_add_series(chart1, LV_COLOR_BLUE);
    dl1_2->points[0] = 100;

    lv_chart_refresh(chart1);


    /* Create a chart with the same data and modify all appearance-like attributes
     * also modify the number of points, range, and type*/
    lv_obj_t * chart2 = lv_chart_create(lv_disp_get_scr_act(NULL), NULL);
    lv_obj_set_size(chart2, 140, 100);
    lv_obj_align(chart2, chart1, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_chart_set_series_darking(chart2, LV_OPA_90);
    lv_chart_set_series_opa(chart2, LV_OPA_40);
    lv_chart_set_series_width(chart2, 4);
    lv_chart_set_type(chart2, LV_CHART_TYPE_POINT | LV_CHART_TYPE_LINE);
    lv_chart_set_range(chart2, -20, 120);
    lv_chart_set_div_line_count(chart2, 4, 0);

    lv_chart_series_t * dl2_1 = lv_chart_add_series(chart2, LV_COLOR_RED);
    dl2_1->points[0] = 0;
    dl2_1->points[1] = 25;
    dl2_1->points[2] = 0;
    dl2_1->points[3] = 50;
    dl2_1->points[4] = 0;
    dl2_1->points[5] = 75;
    dl2_1->points[6] = 0;
    dl2_1->points[7] = 100;
    dl2_1->points[8] = 0;

    lv_chart_series_t * dl2_2 = lv_chart_add_series(chart2, LV_COLOR_BLUE);
    dl2_2->points[0] = 100;

    lv_chart_refresh(chart2);

    lv_chart_set_point_count(chart2, 15);


    /*Copy the previous chart, set COLUMN type and test lv_chart_set_next()*/
    lv_obj_t * chart3 = lv_chart_create(lv_disp_get_scr_act(NULL), chart2);
    lv_obj_align(chart3, chart2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_chart_set_type(chart3, LV_CHART_TYPE_COLUMN);
    lv_chart_series_t * dl3_1 = lv_chart_add_series(chart3, LV_COLOR_RED);
    dl3_1->points[0] = 0;
    dl3_1->points[1] = 25;
    dl3_1->points[2] = 0;
    dl3_1->points[3] = 50;
    dl3_1->points[4] = 0;
    dl3_1->points[5] = 75;
    dl3_1->points[6] = 0;
    dl3_1->points[7] = 100;
    dl3_1->points[8] = 0;

    lv_chart_series_t * dl3_2 = lv_chart_add_series(chart3, LV_COLOR_BLUE);
    dl3_2->points[0] = 100;

    lv_chart_refresh(chart2);

    lv_chart_set_next(chart3, dl3_2, 110);
    lv_chart_set_next(chart3, dl3_2, 110);
    lv_chart_set_next(chart3, dl3_2, 110);
    lv_chart_set_next(chart3, dl3_2, 110);

}

void lv_test_chart_2(uint8_t chart)
{

	static lv_style_t scr_style;
	lv_style_copy(&scr_style, lv_obj_get_style(lv_scr_act()));
	scr_style.body.main_color = LV_COLOR_BLACK;
	scr_style.body.grad_color = LV_COLOR_BLACK;

	lv_obj_set_style(lv_scr_act(), &scr_style);

	static lv_style_t style_chart_label;
	lv_style_copy(&style_chart_label, &lv_style_plain);
	style_chart_label.text.font = &lv_font_dejavu_20;
	style_chart_label.text.color = LV_COLOR_YELLOW;
	style_chart_label.text.opa = LV_OPA_COVER;

	static lv_obj_t * chart_label;
	chart_label = lv_label_create(lv_disp_get_scr_act(NULL), NULL);
	lv_obj_set_style(chart_label, &style_chart_label);
	lv_label_set_align(chart_label, LV_LABEL_ALIGN_CENTER);
	lv_label_set_long_mode(chart_label, LV_LABEL_LONG_EXPAND);
	lv_label_set_text(chart_label, "Choose between 0 and 5");
	lv_obj_align(chart_label, NULL, LV_ALIGN_IN_TOP_MID, 10, 20);

    /*Create charts with axis ticks and labels*/
	static lv_style_t style_chart_axes;
	lv_style_copy(&style_chart_axes, &lv_style_plain);
	style_chart_axes.body.shadow.color = LV_COLOR_WHITE;
	style_chart_axes.body.shadow.width = 0;
	style_chart_axes.line.color = LV_COLOR_GRAY;
	style_chart_axes.line.width = 1;
	style_chart_axes.line.opa = LV_OPA_70;
	style_chart_axes.body.main_color = LV_COLOR_WHITE;
	style_chart_axes.body.grad_color = LV_COLOR_BLACK;
	style_chart_axes.body.opa = LV_OPA_COVER;
	style_chart_axes.body.border.color = LV_COLOR_GREEN;
	style_chart_axes.body.border.width = 1;
	style_chart_axes.body.border.opa = LV_OPA_70;
	style_chart_axes.text.color = LV_COLOR_WHITE;
	style_chart_axes.text.font = &lv_font_dejavu_20;
	style_chart_axes.text.opa = LV_OPA_COVER;

	lv_obj_t * chart_axes = lv_chart_create(lv_disp_get_scr_act(NULL), NULL);
	lv_obj_set_size(chart_axes, (LV_HOR_RES * 0.70), (LV_VER_RES * 0.60) );
	lv_obj_set_style(chart_axes, &style_chart_axes);
	lv_obj_align(chart_axes, chart_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	lv_chart_set_margin(chart_axes, 100);
	lv_chart_set_type(chart_axes, LV_CHART_TYPE_COLUMN);
	lv_chart_set_div_line_count(chart_axes, 0, 0);
	lv_chart_set_point_count(chart_axes, 24);
	lv_chart_set_series_opa(chart_axes, LV_OPA_COVER);
	lv_chart_set_series_width(chart_axes, 1);

	lv_chart_series_t * ser = lv_chart_add_series(chart_axes, LV_COLOR_RED);
	lv_chart_set_range(chart_axes, 0, 100);

	// some pseudo-random data
	uint8_t i;
	for(i = 0; i < 24; i++)
	{
		/* add random points between 0 an 100 */
		lv_chart_set_next(chart_axes, ser, (rand() % 101));
	}

	switch( chart )
	{
		case 0:
		{
			lv_label_set_text(chart_label, "Chart 0");
			lv_chart_set_y_ticks(chart_axes, "0\n" "1\n" "2\n" "3\n" "4\n" "Y[$]", 2, 0, 0, 0 );
			lv_chart_set_x_ticks(chart_axes, "0\n" "1\n" "2\n" "3\n" "4\n" "X[%]", 2, 0, 0, 0 );
			break;
		}

		case 1:
		{
			lv_label_set_text(chart_label, "Chart 1");
			lv_chart_set_y_ticks(chart_axes, "Y[$]\n" "1\n" "2\n" "3\n" "4", 5, 0, 0, LV_CHART_AXIS_DRAW_LAST_TICK );
			lv_chart_set_x_ticks(chart_axes, "X[%]\n" "1\n" "2\n" "3\n" "4", 10, 0, 0, LV_CHART_AXIS_DRAW_LAST_TICK );
			break;
		}

		case 2:
		{
			lv_label_set_text(chart_label, "Chart 2");
			lv_chart_set_y_ticks(chart_axes, "Down\n" "Y\n" "Up", 1, 0, 0, LV_CHART_AXIS_DRAW_LAST_TICK );
			lv_chart_set_x_ticks(chart_axes, "Left\n" "X\n" "Right", 1, 0, 0, LV_CHART_AXIS_DRAW_LAST_TICK );
			break;
		}

		case 3:
		{
			lv_label_set_text(chart_label, "Chart 3");
			lv_chart_set_y_ticks(chart_axes, "0\n" "0.2\n" "0.4\n" "0.6\n" "0.8\n" "P[kW]", 2, 8, 2, 0);
			lv_chart_set_x_ticks(chart_axes, "0\n" "\n" "6\n" "\n" "12\n" "\n" "18\n" "\n" "t[h]", 3, 12, 6, 0 );
			break;
		}

		case 4:
		{
			lv_label_set_text(chart_label, "Chart 4");
			lv_chart_set_y_ticks(chart_axes, NULL, 10, 0, 0, LV_CHART_AXIS_DRAW_LAST_TICK );
			lv_chart_set_x_ticks(chart_axes, NULL, 6, 0, 0, LV_CHART_AXIS_DRAW_LAST_TICK );
			break;
		}

		case 5:
		{
			lv_label_set_text(chart_label, "Chart 5");
			lv_chart_set_y_ticks(chart_axes, "\n\n\n\n\n\n\n\n\n\n", 2, 0, 0, LV_CHART_AXIS_DRAW_LAST_TICK );
			lv_chart_set_x_ticks(chart_axes, "\n\n\n\n\n", 5, 10, 4, LV_CHART_AXIS_DRAW_LAST_TICK );
			break;
		}

		default: {
			break;
		}
	}

	lv_obj_align(chart_label, NULL, LV_ALIGN_IN_TOP_MID, 10, 20);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /*LV_USE_BTN && LV_USE_TESTS*/
