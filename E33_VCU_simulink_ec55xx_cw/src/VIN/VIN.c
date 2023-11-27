

#include "VIN.h"
#include "Std_Types.h"


uint8 ec_VINWRFlag = 0;
uint8 VINRDDATACAN[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint8 ec_VINData[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void ec_VIN_WR(void)
{
	uint16 i = 0;
	uint8 CANReceive_sts = 0;
	//uint8 CANTransmit_sts = 0;
	uint8 CAN2BUF2RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

	CANReceive_sts= ec_can_receive(2,5, CAN2BUF2RX);

	if(CANReceive_sts>0)
	{
		if(1 == CAN2BUF2RX[0])
		{
			uint8 CAN2BUF10TX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

			if((03 == CAN2BUF2RX[1]) && (31 == CAN2BUF2RX[2]))
			{
				CAN2BUF10TX[0]= ((uint8)255U);
				CAN2BUF10TX[1]= ((uint8)03U);
				CAN2BUF10TX[2]= ((uint8)31U);

				ec_VINWRFlag = 9; //连接成功
			}
			if(1 == CAN2BUF2RX[1] && 9 == ec_VINWRFlag)
			{
			  ec_VINData[0] = CAN2BUF2RX[2];
			  ec_VINData[1] = CAN2BUF2RX[3];
			  ec_VINData[2] = CAN2BUF2RX[4];
			  ec_VINData[3] = CAN2BUF2RX[5];
			  ec_VINData[4] = CAN2BUF2RX[6];
			  ec_VINData[5] = CAN2BUF2RX[7];

			  ec_VINWRFlag = 8; //连接成功
			  CAN2BUF10TX[0]= ((uint8)01U);
			  CAN2BUF10TX[1] = (uint8)ec_VINWRFlag;
			}
			if(2 == CAN2BUF2RX[1] && 8 == ec_VINWRFlag)
			{
				ec_VINData[6] = CAN2BUF2RX[2];
				ec_VINData[7] = CAN2BUF2RX[3];
				ec_VINData[8] = CAN2BUF2RX[4];
				ec_VINData[9] = CAN2BUF2RX[5];
				ec_VINData[10] = CAN2BUF2RX[6];
				ec_VINData[11] = CAN2BUF2RX[7];

				ec_VINWRFlag = 7; //连接成功
				CAN2BUF10TX[0]= ((uint8)02U);
				CAN2BUF10TX[1] = (uint8)ec_VINWRFlag;
			}
			if(3 == CAN2BUF2RX[1] && 7 == ec_VINWRFlag)
			{
				ec_VINData[12] = CAN2BUF2RX[2];
				ec_VINData[13] = CAN2BUF2RX[3];
				ec_VINData[14] = CAN2BUF2RX[4];
				ec_VINData[15] = CAN2BUF2RX[5];
				ec_VINData[16] = CAN2BUF2RX[6];
				ec_VINData[17] = CAN2BUF2RX[7];

				if(0x0D == ec_VINData[17])
				{
					ec_VINWRFlag = 6; //接收完成
					ec_VINData[17] = 0;
				}

				  CAN2BUF10TX[0]= ((uint8)03U);
				  CAN2BUF10TX[1] = (uint8)ec_VINWRFlag;
			}

			ec_can_transmit(2, 10, 0, 791U, 8, CAN2BUF10TX);

			i= 50;
			while (i--)
			{
			;
			}
			if(6 == ec_VINWRFlag)
			{
			
				uint16 i= 0;
				
				uint8 ec_returnCode= 0;
				
			    //DisableInterrupts();
			    
			    asm(" wrteei 0");
			    
				ec_returnCode = pFlashErase( &ssdConfig, FALSE, 0x00000008, 0x00000000,0x00000000, NULL_CALLBACK );
			
				if (ec_returnCode != H7F_OK ) {
				  while (1) {
				    ;
				  }
				}

				pFlashProgram( &ssdConfig, 0x0001C000, 24,(uint32)ec_VINData, NULL_CALLBACK );
				i= 1000;
				while (i--) {
				  ;
				}	
				
				
				/* Generate a software system reset */	
				ec_cpu_reset();
	 
			}
		}

		//读取VIN
		if( 02 == CAN2BUF2RX[0])
		{
			uint8 i = 0;
			uint8 CAN2BUF10TX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

			if(31 == CAN2BUF2RX[1] && 03 == CAN2BUF2RX[2])
			{
				//counter6 ++;
				for(i = 0 ; i < 17 ; i++)
				{
					VINRDDATACAN[i] = *(uint8 *)((uint32)0x0001C000 + (uint32)i);

				}
				CAN2BUF10TX[0]= ((uint8)254U);
				CAN2BUF10TX[1]= ((uint8)03U);
				CAN2BUF10TX[2]= ((uint8)31U);

				ec_VINWRFlag = 5;

			}
			if(01 == CAN2BUF2RX[1])
			{

				CAN2BUF10TX[0] = (uint8)1;
				CAN2BUF10TX[1] = VINRDDATACAN[0];
				CAN2BUF10TX[2] = VINRDDATACAN[1];
				CAN2BUF10TX[3] = VINRDDATACAN[2];
				CAN2BUF10TX[4] = VINRDDATACAN[3];
				CAN2BUF10TX[5] = VINRDDATACAN[4];
				CAN2BUF10TX[6] = VINRDDATACAN[5];
				CAN2BUF10TX[7] = VINRDDATACAN[6];

				ec_VINWRFlag = 4;
			}
			if(02 == CAN2BUF2RX[1])
			{
				CAN2BUF10TX[0] = (uint8)2;
				CAN2BUF10TX[1] = VINRDDATACAN[7];
				CAN2BUF10TX[2] = VINRDDATACAN[8];
				CAN2BUF10TX[3] = VINRDDATACAN[9];
				CAN2BUF10TX[4] = VINRDDATACAN[10];
				CAN2BUF10TX[5] = VINRDDATACAN[11];
				CAN2BUF10TX[6] = VINRDDATACAN[12];
				CAN2BUF10TX[7] = VINRDDATACAN[13];

				ec_VINWRFlag = 3;

			}
			if(03 == CAN2BUF2RX[1])
			{
				CAN2BUF10TX[0] = (uint8)3;
				CAN2BUF10TX[1] = VINRDDATACAN[14];
				CAN2BUF10TX[2] = VINRDDATACAN[15];
				CAN2BUF10TX[3] = VINRDDATACAN[16];
				CAN2BUF10TX[4] = (uint8)10;
				CAN2BUF10TX[5] = (uint8)10;
				CAN2BUF10TX[6] = (uint8)10;
				CAN2BUF10TX[7] = (uint8)10;
				//ec_VINWRFlag = 3;
			}

			ec_can_transmit(2, 10, 0, 791U, 8, CAN2BUF10TX);
			i= 100;
			while (i--)
			{
				;
			}
		}
	}
}






void ec_VIN_RD(uint8 VINRDDATA[])
{
	uint8 i = 0;

	for(i = 0 ; i < 17 ; i++)
	{
		VINRDDATA[i] = *(uint8 *)((uint32)0x0001C000 + (uint32)i);

	}

}
