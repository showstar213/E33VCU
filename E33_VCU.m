
%% SCS短路判定阈值标定
SCS_Error_5V = 4500;                           %unit: mV  判定模拟SCS是否与5v电源短路
SCS_Error_5V = ecucoder_cal(SCS_Error_5V);

SCS_Error_GND = 200;                           %unit: mV  判定模拟SCS是否与GND短路
SCS_Error_GND = ecucoder_cal(SCS_Error_GND);
%% 加速踏板标定
APPS_Map = [0,1000];                            %加速踏板开度

APPS1_Voltage  = [445,1800];                     %加速踏板传感器1信号 单位 mV
APPS1_Voltage  = ecucoder_cal(APPS1_Voltage);    %将Voltage设为标定量

APPS2_Voltage  = [1135,2710];                     %加速踏板传感器2信号 单位 mV
APPS2_Voltage  = ecucoder_cal(APPS2_Voltage);    %将Voltage设为标定量
%% 制动踏板标定
BP_Map = [0,1000];

BP_F_Voltage  = [500,2800];
BP_F_Voltage  = ecucoder_cal(BP_F_Voltage);

BP_R_Voltage  = [510,1200];
BP_R_Voltage  = ecucoder_cal(BP_R_Voltage);
%% 尾灯亮度标定
Brk_luminance = 50;
Brk_luminance  = ecucoder_cal(Brk_luminance);

HardBrk_luminance = 150;
HardBrk_luminance  = ecucoder_cal(HardBrk_luminance);
%% 轮速传感器标定
SPD_Coef = 1884/40;                               %轮速系数 = 滚动周长/齿轮齿数
%% 线位移传感器标定
linear_Map = [0,1000];
linear_Map = ecucoder_cal(linear_Map);

linear_RR_Map = [0,24000];
linear_RR_Map  = ecucoder_cal(linear_RR_Map);

linear_FR_Map = [0,24000];
linear_FR_Map  = ecucoder_cal(linear_FR_Map);

linear_RL_Map = [0,24000];
linear_RL_Map  = ecucoder_cal(linear_RL_Map);

linear_FL_Map = [0,24000];
linear_FL_Map  = ecucoder_cal(linear_FL_Map);
%% 转向角位移传感器标定
Angle_Map = [0,1000];
Angle_Map = ecucoder_cal(Angle_Map);

Angle = 0;
Angle = ecucoder_cal(Angle);
%% 整车热管理标定
Tmanage_Map = [0,100];

Accu_FAN_threshold = [25,30];
Accu_FAN_threshold = ecucoder_cal(Accu_FAN_threshold);

Tail_FAN_threshold = [25,30];
Tail_FAN_threshold = ecucoder_cal(Tail_FAN_threshold);

Pump_threshold = 30;
Pump_threshold = ecucoder_cal(Pump_threshold);

Radiator_FAN_threshold = [30,40];
Radiator_FAN_threshold = ecucoder_cal(Radiator_FAN_threshold);
%% 待驶逻辑标定
BP_F_threshold = 10;                                                        %油压踏板触发待驶逻辑阈值 unit: 百分比
BP_F_threshold = ecucoder_cal(BP_F_threshold);

APPS_threshold = 50;                                                         %加速踏板触发待驶逻辑阈值 unit: 百分比
APPS_threshold = ecucoder_cal(APPS_threshold);

Beep_Time = 2;                                                              %蜂鸣器蜂鸣时间 unit: s（最少1s 最多3s）
Beep_Time = ecucoder_cal(Beep_Time);
%% Kemo控制器最大指令阶跃标定
MaxTorqChangePerSec = 25000;                                               
MaxTorqChangePerSec = ecucoder_cal(MaxTorqChangePerSec);

MaxRPMchangePerSec = 20000;
MaxRPMchangePerSec = ecucoder_cal(MaxRPMchangePerSec);
%% 扭矩Map标定

MaxRPM  = 5400;                %最大转速  unit: RPM 
MaxTorq = 180;                 %最大扭矩  unit: Nm
MaxPow  = 40;                  %最大功率  unit: W

%绘制Map图 （X轴：转速，Y轴：加速踏板开度，Z轴：扭矩）
%--------------------------------------------------%
Motor_RPM_Map = (0:ceil(MaxRPM/100))*100;                                   % X轴变量 电机转速  unit: RPM

Len = length(Motor_RPM_Map);
Motor_Torq_MAP = zeros(2,Len);
    for i=1:Len-1
        Motor_Torq_MAP (2,i) = min(MaxPow*9548.8/Motor_RPM_Map(i),MaxTorq); %电机扭矩
    end
    
surf(Motor_RPM_Map,APPS_Map,Motor_Torq_MAP,'LineStyle',':','FaceColor','interp')
%--------------------------------------------------%
Torq_percentage_Map= Motor_Torq_MAP/MaxTorq*1000;                           %扭矩百分比  unit: Nm  % Z轴变量 电机扭矩输出百分比
%% 工装模式标定
TEST = 0;
TEST = ecucoder_cal(TEST);

FactoryTestEnable = 0;
FactoryTestEnable = ecucoder_cal(FactoryTestEnable);

BeeperTest   = 0;
BeeperTest   = ecucoder_cal(BeeperTest);

R2D_Light_Test   = 0;
R2D_Light_Test   = ecucoder_cal(R2D_Light_Test);

BMSLedTest   = 0;
BMSLedTest   = ecucoder_cal(BMSLedTest);

IMDLedTest   = 0;
IMDLedTest   = ecucoder_cal(IMDLedTest);

Tail_Light_Test = 0;
Tail_Light_Test = ecucoder_cal(Tail_Light_Test);

DCDC_Relay_Test = 0;
DCDC_Relay_Test = ecucoder_cal(DCDC_Relay_Test);

Accu_FAN_Test = 0;
Accu_FAN_Test = ecucoder_cal(Accu_FAN_Test);

Tail_FAN_Test = 0;
Tail_FAN_Test = ecucoder_cal(Tail_FAN_Test);

Pump_Test = 0;
Pump_Test = ecucoder_cal(Pump_Test);

Radiator_FAN_Test = 0;
Radiator_FAN_Test = ecucoder_cal(Radiator_FAN_Test);