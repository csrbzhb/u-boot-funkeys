/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * logicore_dp_dpcd.h
 *
 * DPCD interface definition for XILINX LogiCore DisplayPort v6.1
 * based on Xilinx dp_v3_1 driver sources
 *
 * (C) Copyright 2016
 * Dirk Eibach,  Guntermann & Drunck GmbH, dirk.eibach@gdsys.cc
 */

#ifndef __GDSYS_LOGICORE_DP_DPCD_H__
#define __GDSYS_LOGICORE_DP_DPCD_H__

/* receiver capability field */
#define DPCD_REV						0x00000
#define DPCD_MAX_LINK_RATE					0x00001
#define DPCD_MAX_LANE_COUNT					0x00002
#define DPCD_MAX_DOWNSPREAD					0x00003
#define DPCD_NORP_PWR_V_CAP					0x00004
#define DPCD_DOWNSP_PRESENT					0x00005
#define DPCD_ML_CH_CODING_CAP					0x00006
#define DPCD_DOWNSP_COUNT_MSA_OUI				0x00007
#define	DPCD_RX_PORT0_CAP_0					0x00008
#define	DPCD_RX_PORT0_CAP_1					0x00009
#define	DPCD_RX_PORT1_CAP_0					0x0000A
#define	DPCD_RX_PORT1_CAP_1					0x0000B
#define DPCD_I2C_SPEED_CTL_CAP					0x0000C
#define DPCD_EDP_CFG_CAP					0x0000D
#define DPCD_TRAIN_AUX_RD_INTERVAL				0x0000E
#define DPCD_ADAPTER_CAP					0x0000F
#define DPCD_FAUX_CAP						0x00020
#define DPCD_MSTM_CAP						0x00021
#define DPCD_NUM_AUDIO_EPS					0x00022
#define	DPCD_AV_GRANULARITY					0x00023
#define DPCD_AUD_DEC_LAT_7_0					0x00024
#define DPCD_AUD_DEC_LAT_15_8					0x00025
#define DPCD_AUD_PP_LAT_7_0					0x00026
#define DPCD_AUD_PP_LAT_15_8					0x00027
#define DPCD_VID_INTER_LAT					0x00028
#define DPCD_VID_PROG_LAT					0x00029
#define DPCD_REP_LAT						0x0002A
#define DPCD_AUD_DEL_INS_7_0					0x0002B
#define DPCD_AUD_DEL_INS_15_8					0x0002C
#define DPCD_AUD_DEL_INS_23_16					0x0002D
#define DPCD_GUID						0x00030
#define DPCD_RX_GTC_VALUE_7_0					0x00054
#define DPCD_RX_GTC_VALUE_15_8					0x00055
#define DPCD_RX_GTC_VALUE_23_16					0x00056
#define DPCD_RX_GTC_VALUE_31_24					0x00057
#define DPCD_RX_GTC_MSTR_REQ					0x00058
#define DPCD_RX_GTC_FREQ_LOCK_DONE				0x00059
#define DPCD_DOWNSP_0_CAP					0x00080
#define DPCD_DOWNSP_1_CAP					0x00081
#define DPCD_DOWNSP_2_CAP					0x00082
#define DPCD_DOWNSP_3_CAP					0x00083
#define DPCD_DOWNSP_0_DET_CAP					0x00080
#define DPCD_DOWNSP_1_DET_CAP					0x00084
#define DPCD_DOWNSP_2_DET_CAP					0x00088
#define DPCD_DOWNSP_3_DET_CAP					0x0008C

/* link configuration field */
#define DPCD_LINK_BW_SET					0x00100
#define DPCD_LANE_COUNT_SET					0x00101
#define DPCD_TP_SET						0x00102
#define DPCD_TRAINING_LANE0_SET					0x00103
#define DPCD_TRAINING_LANE1_SET					0x00104
#define DPCD_TRAINING_LANE2_SET					0x00105
#define DPCD_TRAINING_LANE3_SET					0x00106
#define DPCD_DOWNSPREAD_CTRL					0x00107
#define DPCD_ML_CH_CODING_SET					0x00108
#define DPCD_I2C_SPEED_CTL_SET					0x00109
#define DPCD_EDP_CFG_SET					0x0010A
#define DPCD_LINK_QUAL_LANE0_SET				0x0010B
#define DPCD_LINK_QUAL_LANE1_SET				0x0010C
#define DPCD_LINK_QUAL_LANE2_SET				0x0010D
#define DPCD_LINK_QUAL_LANE3_SET				0x0010E
#define DPCD_TRAINING_LANE0_1_SET2				0x0010F
#define DPCD_TRAINING_LANE2_3_SET2				0x00110
#define DPCD_MSTM_CTRL						0x00111
#define DPCD_AUDIO_DELAY_7_0					0x00112
#define DPCD_AUDIO_DELAY_15_8					0x00113
#define DPCD_AUDIO_DELAY_23_6					0x00114
#define DPCD_UPSTREAM_DEVICE_DP_PWR_NEED			0x00118
#define DPCD_FAUX_MODE_CTRL					0x00120
#define DPCD_FAUX_FORWARD_CH_DRIVE_SET				0x00121
#define DPCD_BACK_CH_STATUS					0x00122
#define DPCD_FAUX_BACK_CH_SYMBOL_ERROR_COUNT			0x00123
#define DPCD_FAUX_BACK_CH_TRAINING_PATTERN_TIME			0x00125
#define DPCD_TX_GTC_VALUE_7_0					0x00154
#define DPCD_TX_GTC_VALUE_15_8					0x00155
#define DPCD_TX_GTC_VALUE_23_16					0x00156
#define DPCD_TX_GTC_VALUE_31_24					0x00157
#define DPCD_RX_GTC_VALUE_PHASE_SKEW_EN				0x00158
#define DPCD_TX_GTC_FREQ_LOCK_DONE				0x00159
#define DPCD_ADAPTER_CTRL					0x001A0
#define DPCD_BRANCH_DEVICE_CTRL					0x001A1
#define DPCD_PAYLOAD_ALLOCATE_SET				0x001C0
#define DPCD_PAYLOAD_ALLOCATE_START_TIME_SLOT			0x001C1
#define DPCD_PAYLOAD_ALLOCATE_TIME_SLOT_COUNT			0x001C2

/* link/sink status field */
#define DPCD_SINK_COUNT						0x00200
#define DPCD_DEVICE_SERVICE_IRQ					0x00201
#define DPCD_STATUS_LANE_0_1					0x00202
#define DPCD_STATUS_LANE_2_3					0x00203
#define DPCD_LANE_ALIGN_STATUS_UPDATED				0x00204
#define DPCD_SINK_STATUS					0x00205
#define DPCD_ADJ_REQ_LANE_0_1					0x00206
#define DPCD_ADJ_REQ_LANE_2_3					0x00207
#define DPCD_TRAINING_SCORE_LANE_0				0x00208
#define DPCD_TRAINING_SCORE_LANE_1				0x00209
#define DPCD_TRAINING_SCORE_LANE_2				0x0020A
#define DPCD_TRAINING_SCORE_LANE_3				0x0020B
#define DPCD_ADJ_REQ_PC2					0x0020C
#define DPCD_FAUX_FORWARD_CH_SYMBOL_ERROR_COUNT			0x0020D
#define DPCD_SYMBOL_ERROR_COUNT_LANE_0				0x00210
#define DPCD_SYMBOL_ERROR_COUNT_LANE_1				0x00212
#define DPCD_SYMBOL_ERROR_COUNT_LANE_2				0x00214
#define DPCD_SYMBOL_ERROR_COUNT_LANE_3				0x00216

/* automated testing sub-field */
#define DPCD_FAUX_FORWARD_CH_STATUS				0x00280
#define DPCD_FAUX_BACK_CH_DRIVE_SET				0x00281
#define DPCD_FAUX_BACK_CH_SYM_ERR_COUNT_CTRL			0x00282
#define DPCD_PAYLOAD_TABLE_UPDATE_STATUS			0x002C0
#define DPCD_VC_PAYLOAD_ID_SLOT(slotnum) \
			(DPCD_PAYLOAD_TABLE_UPDATE_STATUS + slotnum)

/* sink control field */
#define DPCD_SET_POWER_DP_PWR_VOLTAGE				0x00600

/* sideband message buffers */
#define DPCD_DOWN_REQ						0x01000
#define DPCD_UP_REP						0x01200
#define DPCD_DOWN_REP						0x01400
#define DPCD_UP_REQ						0x01600

/* event status indicator field */
#define DPCD_SINK_COUNT_ESI					0x02002
#define DPCD_SINK_DEVICE_SERVICE_IRQ_VECTOR_ESI0		0x02003
#define DPCD_SINK_DEVICE_SERVICE_IRQ_VECTOR_ESI1		0x02004
#define DPCD_SINK_LINK_SERVICE_IRQ_VECTOR_ESI0			0x02005
#define DPCD_SINK_LANE0_1_STATUS				0x0200C
#define DPCD_SINK_LANE2_3_STATUS				0x0200D
#define DPCD_SINK_ALIGN_STATUS_UPDATED_ESI			0x0200E
#define DPCD_SINK_STATUS_ESI					0x0200F

/*
 * field addresses and sizes.
 */
#define DPCD_RECEIVER_CAP_FIELD_START				DPCD_REV
#define DPCD_RECEIVER_CAP_FIELD_SIZE				0x100
#define DPCD_LINK_CFG_FIELD_START				DPCD_LINK_BW_SET
#define DPCD_LINK_CFG_FIELD_SIZE				0x100
#define DPCD_LINK_SINK_STATUS_FIELD_START			DPCD_SINK_COUNT
#define DPCD_LINK_SINK_STATUS_FIELD_SIZE			0x17
/* 0x00000: DPCD_REV */
#define DPCD_REV_MNR_MASK					0x0F
#define DPCD_REV_MJR_MASK					0xF0
#define DPCD_REV_MJR_SHIFT					4
/* 0x00001: MAX_LINK_RATE */
#define DPCD_MAX_LINK_RATE_162GBPS				0x06
#define DPCD_MAX_LINK_RATE_270GBPS				0x0A
#define DPCD_MAX_LINK_RATE_540GBPS				0x14
/* 0x00002: MAX_LANE_COUNT */
#define DPCD_MAX_LANE_COUNT_MASK				0x1F
#define DPCD_MAX_LANE_COUNT_1					0x01
#define DPCD_MAX_LANE_COUNT_2					0x02
#define DPCD_MAX_LANE_COUNT_4					0x04
#define DPCD_TPS3_SUPPORT_MASK					0x40
#define DPCD_ENHANCED_FRAME_SUPPORT_MASK			0x80
/* 0x00003: MAX_DOWNSPREAD */
#define DPCD_MAX_DOWNSPREAD_MASK				0x01
#define DPCD_NO_AUX_HANDSHAKE_LINK_TRAIN_MASK			0x40
/* 0x00005: DOWNSP_PRESENT */
#define DPCD_DOWNSP_PRESENT_MASK				0x01
#define DPCD_DOWNSP_TYPE_MASK					0x06
#define DPCD_DOWNSP_TYPE_SHIFT					1
#define DPCD_DOWNSP_TYPE_DP					0x0
#define DPCD_DOWNSP_TYPE_AVGA_ADVII				0x1
#define DPCD_DOWNSP_TYPE_DVI_HDMI_DPPP				0x2
#define DPCD_DOWNSP_TYPE_OTHERS					0x3
#define DPCD_DOWNSP_FORMAT_CONV_MASK				0x08
#define DPCD_DOWNSP_DCAP_INFO_AVAIL_MASK			0x10
/* 0x00006, 0x00108: ML_CH_CODING_SUPPORT, ML_CH_CODING_SET */
#define DPCD_ML_CH_CODING_MASK					0x01
/* 0x00007: DOWNSP_COUNT_MSA_OUI */
#define DPCD_DOWNSP_COUNT_MASK					0x0F
#define DPCD_MSA_TIMING_PAR_IGNORED_MASK			0x40
#define DPCD_OUI_SUPPORT_MASK					0x80
/* 0x00008, 0x0000A: RX_PORT[0-1]_CAP_0 */
#define DPCD_RX_PORTX_CAP_0_LOCAL_EDID_PRESENT_MASK		0x02
#define DPCD_RX_PORTX_CAP_0_ASSOC_TO_PRECEDING_PORT_MASK	0x04
/* 0x0000C, 0x00109: I2C_SPEED_CTL_CAP, I2C_SPEED_CTL_SET */
#define DPCD_I2C_SPEED_CTL_NONE					0x00
#define DPCD_I2C_SPEED_CTL_1KBIPS				0x01
#define DPCD_I2C_SPEED_CTL_5KBIPS				0x02
#define DPCD_I2C_SPEED_CTL_10KBIPS				0x04
#define DPCD_I2C_SPEED_CTL_100KBIPS				0x08
#define DPCD_I2C_SPEED_CTL_400KBIPS				0x10
#define DPCD_I2C_SPEED_CTL_1MBIPS				0x20
/* 0x0000E: TRAIN_AUX_RD_INTERVAL */
#define DPCD_TRAIN_AUX_RD_INT_100_400US				0x00
#define DPCD_TRAIN_AUX_RD_INT_4MS				0x01
#define DPCD_TRAIN_AUX_RD_INT_8MS				0x02
#define DPCD_TRAIN_AUX_RD_INT_12MS				0x03
#define DPCD_TRAIN_AUX_RD_INT_16MS				0x04
/* 0x00020: DPCD_FAUX_CAP */
#define DPCD_FAUX_CAP_MASK					0x01
/* 0x00021: MSTM_CAP */
#define DPCD_MST_CAP_MASK					0x01
/* 0x00080, 0x00081|4, 0x00082|8, 0x00083|C: DOWNSP_X_(DET_)CAP */
#define DPCD_DOWNSP_X_CAP_TYPE_MASK				0x07
#define DPCD_DOWNSP_X_CAP_TYPE_DP				0x0
#define DPCD_DOWNSP_X_CAP_TYPE_AVGA				0x1
#define DPCD_DOWNSP_X_CAP_TYPE_DVI				0x2
#define DPCD_DOWNSP_X_CAP_TYPE_HDMI				0x3
#define DPCD_DOWNSP_X_CAP_TYPE_OTHERS				0x4
#define DPCD_DOWNSP_X_CAP_TYPE_DPPP				0x5
#define DPCD_DOWNSP_X_CAP_HPD_MASK				0x80
#define DPCD_DOWNSP_X_CAP_NON_EDID_ATTR_MASK			0xF0
#define DPCD_DOWNSP_X_CAP_NON_EDID_ATTR_SHIFT			4
#define DPCD_DOWNSP_X_CAP_NON_EDID_ATTR_720_480_I_60		0x1
#define DPCD_DOWNSP_X_CAP_NON_EDID_ATTR_720_480_I_50		0x2
#define DPCD_DOWNSP_X_CAP_NON_EDID_ATTR_1920_1080_I_60		0x3
#define DPCD_DOWNSP_X_CAP_NON_EDID_ATTR_1920_1080_I_50		0x4
#define DPCD_DOWNSP_X_CAP_NON_EDID_ATTR_1280_720_P_60		0x5
#define DPCD_DOWNSP_X_CAP_NON_EDID_ATTR_1280_720_P_50		0x7
/* 0x00082, 0x00086, 0x0008A, 0x0008E: DOWNSP_X_(DET_)CAP2 */
#define DPCD_DOWNSP_X_DCAP_MAX_BPC_MASK				0x03
#define DPCD_DOWNSP_X_DCAP_MAX_BPC_8				0x0
#define DPCD_DOWNSP_X_DCAP_MAX_BPC_10				0x1
#define DPCD_DOWNSP_X_DCAP_MAX_BPC_12				0x2
#define DPCD_DOWNSP_X_DCAP_MAX_BPC_16				0x3
/* 0x00082, 0x00086, 0x0008A, 0x0008E: DOWNSP_X_(DET_)CAP2 */
#define DPCD_DOWNSP_X_DCAP_HDMI_DPPP_FS2FP_MASK			0x01
#define DPCD_DOWNSP_X_DCAP_DVI_DL_MASK				0x02
#define DPCD_DOWNSP_X_DCAP_DVI_HCD_MASK				0x04

/* link configuration field masks, shifts, and register values */
/* 0x00100: DPCD_LINK_BW_SET */
#define DPCD_LINK_BW_SET_162GBPS				0x06
#define DPCD_LINK_BW_SET_270GBPS				0x0A
#define DPCD_LINK_BW_SET_540GBPS				0x14
/* 0x00101: LANE_COUNT_SET */
#define DPCD_LANE_COUNT_SET_MASK				0x1F
#define DPCD_LANE_COUNT_SET_1					0x01
#define DPCD_LANE_COUNT_SET_2					0x02
#define DPCD_LANE_COUNT_SET_4					0x04
#define DPCD_ENHANCED_FRAME_EN_MASK				0x80
/* 0x00102: TP_SET */
#define DPCD_TP_SEL_MASK					0x03
#define DPCD_TP_SEL_OFF						0x0
#define DPCD_TP_SEL_TP1						0x1
#define DPCD_TP_SEL_TP2						0x2
#define DPCD_TP_SEL_TP3						0x3
#define DPCD_TP_SET_LQP_MASK					0x06
#define DPCD_TP_SET_LQP_SHIFT					2
#define DPCD_TP_SET_LQP_OFF					0x0
#define DPCD_TP_SET_LQP_D102_TEST				0x1
#define DPCD_TP_SET_LQP_SER_MES					0x2
#define DPCD_TP_SET_LQP_PRBS7					0x3
#define DPCD_TP_SET_REC_CLK_OUT_EN_MASK				0x10
#define DPCD_TP_SET_SCRAMB_DIS_MASK				0x20
#define DPCD_TP_SET_SE_COUNT_SEL_MASK				0xC0
#define DPCD_TP_SET_SE_COUNT_SEL_SHIFT				6
#define DPCD_TP_SET_SE_COUNT_SEL_DE_ISE				0x0
#define DPCD_TP_SET_SE_COUNT_SEL_DE				0x1
#define DPCD_TP_SET_SE_COUNT_SEL_ISE				0x2
/* 0x00103-0x00106: TRAINING_LANE[0-3]_SET */
#define DPCD_TRAINING_LANEX_SET_VS_MASK				0x03
#define DPCD_TRAINING_LANEX_SET_MAX_VS_MASK			0x04
#define DPCD_TRAINING_LANEX_SET_PE_MASK				0x18
#define DPCD_TRAINING_LANEX_SET_PE_SHIFT			3
#define DPCD_TRAINING_LANEX_SET_MAX_PE_MASK			0x20
/* 0x00107: DOWNSPREAD_CTRL */
#define DPCD_SPREAD_AMP_MASK					0x10
#define DPCD_MSA_TIMING_PAR_IGNORED_EN_MASK			0x80
/* 0x00108: ML_CH_CODING_SET - Same as 0x00006: ML_CH_CODING_SUPPORT */
/* 0x00109: I2C_SPEED_CTL_SET - Same as 0x0000C: I2C_SPEED_CTL_CAP */
/* 0x0010F-0x00110: TRAINING_LANE[0_1-2_3]_SET2 */
#define DPCD_TRAINING_LANE_0_2_SET_PC2_MASK			0x03
#define DPCD_TRAINING_LANE_0_2_SET_MAX_PC2_MASK			0x04
#define DPCD_TRAINING_LANE_1_3_SET_PC2_MASK			0x30
#define DPCD_TRAINING_LANE_1_3_SET_PC2_SHIFT			4
#define DPCD_TRAINING_LANE_1_3_SET_MAX_PC2_MASK			0x40
/* 0x00111: MSTM_CTRL */
#define DPCD_MST_EN_MASK					0x01
#define DPCD_UP_REQ_EN_MASK					0x02
#define DPCD_UP_IS_SRC_MASK					0x03

/* link/sink status field masks, shifts, and register values */
/* 0x00200: SINK_COUNT */
#define DPCD_SINK_COUNT_LOW_MASK				0x3F
#define DPCD_SINK_CP_READY_MASK					0x40
#define DPCD_SINK_COUNT_HIGH_MASK				0x80
#define DPCD_SINK_COUNT_HIGH_LOW_SHIFT				1
/* 0x00202: STATUS_LANE_0_1 */
#define DPCD_STATUS_LANE_0_CR_DONE_MASK				0x01
#define DPCD_STATUS_LANE_0_CE_DONE_MASK				0x02
#define DPCD_STATUS_LANE_0_SL_DONE_MASK				0x04
#define DPCD_STATUS_LANE_1_CR_DONE_MASK				0x10
#define DPCD_STATUS_LANE_1_CE_DONE_MASK				0x20
#define DPCD_STATUS_LANE_1_SL_DONE_MASK				0x40
/* 0x00202: STATUS_LANE_2_3 */
#define DPCD_STATUS_LANE_2_CR_DONE_MASK				0x01
#define DPCD_STATUS_LANE_2_CE_DONE_MASK				0x02
#define DPCD_STATUS_LANE_2_SL_DONE_MASK				0x04
#define DPCD_STATUS_LANE_3_CR_DONE_MASK				0x10
#define DPCD_STATUS_LANE_3_CE_DONE_MASK				0x20
#define DPCD_STATUS_LANE_3_SL_DONE_MASK				0x40
/* 0x00204: LANE_ALIGN_STATUS_UPDATED */
#define DPCD_LANE_ALIGN_STATUS_UPDATED_IA_DONE_MASK \
								0x01
#define DPCD_LANE_ALIGN_STATUS_UPDATED_DOWNSP_STATUS_CHANGED_MASK \
								0x40
#define DPCD_LANE_ALIGN_STATUS_UPDATED_LINK_STATUS_UPDATED_MASK \
								0x80
/* 0x00205: SINK_STATUS */
#define DPCD_SINK_STATUS_RX_PORT0_SYNC_STATUS_MASK		0x01
#define DPCD_SINK_STATUS_RX_PORT1_SYNC_STATUS_MASK		0x02

/* 0x00206, 0x00207: ADJ_REQ_LANE_[0,2]_[1,3] */
#define DPCD_ADJ_REQ_LANE_0_2_VS_MASK				0x03
#define DPCD_ADJ_REQ_LANE_0_2_PE_MASK				0x0C
#define DPCD_ADJ_REQ_LANE_0_2_PE_SHIFT				2
#define DPCD_ADJ_REQ_LANE_1_3_VS_MASK				0x30
#define DPCD_ADJ_REQ_LANE_1_3_VS_SHIFT				4
#define DPCD_ADJ_REQ_LANE_1_3_PE_MASK				0xC0
#define DPCD_ADJ_REQ_LANE_1_3_PE_SHIFT				6
/* 0x0020C: ADJ_REQ_PC2 */
#define DPCD_ADJ_REQ_PC2_LANE_0_MASK				0x03
#define DPCD_ADJ_REQ_PC2_LANE_1_MASK				0x0C
#define DPCD_ADJ_REQ_PC2_LANE_1_SHIFT				2
#define DPCD_ADJ_REQ_PC2_LANE_2_MASK				0x30
#define DPCD_ADJ_REQ_PC2_LANE_2_SHIFT				4
#define DPCD_ADJ_REQ_PC2_LANE_3_MASK				0xC0
#define DPCD_ADJ_REQ_PC2_LANE_3_SHIFT				6

#endif /* __GDSYS_LOGICORE_DP_DPCD_H__ */