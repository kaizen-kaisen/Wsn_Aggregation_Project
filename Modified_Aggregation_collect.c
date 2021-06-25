/*
 * Copyright (c) 2007, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 */

/**
 * \file
 *         Example of how the collect primitive works.
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include "contiki.h"
#include "lib/random.h"
#include "net/rime.h"
#include "net/rime/collect.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"
#include "dev/serial-line.h"
//#include "collect-view.h"

//#define WITH_COFFEE 0
#include "net/netstack.h"
#include "string.h"
#include <stdio.h>

static struct collect_conn tc;
int temp[4] = {-1,-1,-1,-1};
char arr[100];
int count=0;
char arr1[100];
int count1=0;
char arr2[100];
int count2=0;
char arr3[100];
int count3=0;
char arg[100];

/*---------------------------------------------------------------------------*/
PROCESS(example_collect_process, "Test collect process");
AUTOSTART_PROCESSES(&example_collect_process);
/*---------------------------------------------------------------------------*/
static void
recv(const rimeaddr_t *originator, uint8_t seqno, uint8_t hops)
{
  printf("Sink got message from %d.%d, seqno %d, hops %d: len %d '%s'\n",
	 originator->u8[0], originator->u8[1],
	 seqno, hops,
	 packetbuf_datalen(),
	 (char *)packetbuf_dataptr());
}
/*---------------------------------------------------------------------------*/
static const struct collect_callbacks callbacks = { recv };
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(example_collect_process, ev, data)
{
//	printf("hi\n");
	static struct etimer periodic;
	static struct etimer et;
        static struct etimer delay;
       
	PROCESS_BEGIN();

/*

//power on
 serial_shell_init();
 shell_blink_init();

#if WITH_COFFEE
  shell_file_init();
  shell_coffee_init();
#endif /* WITH_COFFEE */
/*
  /* shell_download_init(); */
  /* shell_rime_sendcmd_init(); */
  /* shell_ps_init(); */
/*
  shell_reboot_init();
  shell_rime_init();
  shell_rime_netcmd_init();*/
  /* shell_rime_ping_init(); */
  /* shell_rime_debug_init(); */
  /* shell_rime_debug_runicast_init(); */
 // shell_powertrace_init();
  /* shell_base64_init(); */
 // shell_text_init();
  //shell_time_init();
  /* shell_checkpoint_init(); */
  /* shell_sendtest_init(); */
/*
#if CONTIKI_TARGET_SKY
  shell_sky_init();
#endif /* CONTIKI_TARGET_SKY */
/*
  shell_collect_view_init();
//power off
*/
  collect_open(&tc, 130, COLLECT_ROUTER, &callbacks);
  if(rimeaddr_node_addr.u8[0] == 1 &&
     rimeaddr_node_addr.u8[1] == 0) {
	printf("I am sink\n");
	collect_set_sink(&tc, 1);
  }
  /* Allow some time for the network to settle. */
  etimer_set(&et, 0 * CLOCK_SECOND);
  PROCESS_WAIT_UNTIL(etimer_expired(&et));
  //static int temp[4] = {-1,-1,-1,-1};

etimer_set(&delay, 0.001 * CLOCK_SECOND);
  while(1) {
	
    /* Send a packet every 30 seconds. */
    if(etimer_expired(&periodic)) {
     etimer_set(&periodic, CLOCK_SECOND * 30);
     etimer_set(&et, random_rand() % (CLOCK_SECOND * 30));
    }
	
    PROCESS_WAIT_EVENT();
		/*****************************************************************************/
		
		if(ev == serial_line_event_message && data != NULL) {
				
				int i,j;
				static struct etimer et;
				static struct timer t;
				timer_set(&t, CLOCK_SECOND * 10);
				printf("broadcast message sent\n");
				if(timer_expired(&t)){
				   printf("Timer expired\n");
				}
				
			     printf("I got the message as from %d.%d :-  ",rimeaddr_node_addr.u8[0],rimeaddr_node_addr.u8[1]);

                 char id[50];						
						sprintf(id,"node_id %d.%d ", rimeaddr_node_addr.u8[0],rimeaddr_node_addr.u8[1]);
			    char *line=NULL;
			    
			    line = (char *)data;
			    printf("%s\n",line);
			     static rimeaddr_t oldparent;
			      const rimeaddr_t *parent;
				int index = (int) line[0]-'0';

				if(index <=3 && index >=0)
				{
					if(1)
					{	if(etimer_expired(&et)) 
						{	
					    if(index == 0)
					    {
						temp[index] = index;


						printf("Sending message\n");
						for(j=0;line[j] != '\0';j++)
						{
							arr[count++] = line[j];
						}
							arr[count++] = " ";
                                                
						strcat(arr,id);
					    }

					    if(index == 1)
					    {
						temp[index] = index;
					
                        

						printf("Sending message\n");
						for(j=0;line[j] != '\0';j++)
						{
							arr1[count1++] = line[j];
						}
							arr1[count1++] = " ";
                          
						strcat(arr1,id);
					    }


                        if(index == 2)
					    {
						temp[index] = index;
                       
                       

						printf("Sending message\n");
						for(j=0;line[j] != '\0';j++)
						{
							arr2[count2++] = line[j];
						}
							arr2[count2++] = " ";
                        
						strcat(arr2,id);
					    }



					      
                        if(index == 3)
					    {
						temp[index] = index;
                         
                        
                        
						printf("Sending message\n");
						for(j=0;line[j] != '\0';j++)
						{
							arr3[count3++] = line[j];
						}
							arr3[count3++] = " ";
                        
						 strcat(arr2,id);
					     }	

															
					     timer_set(&t, CLOCK_SECOND * 50);

			      			packetbuf_clear();
                      long long int t=0,i=0;
				for(i=0;i<10000000000;i++)
				{t++;}
                    
			printf("here comes aggregated data\n");
	
                    if(timer_expired(&delay))//wait other nodes so that msg not colide 
                        {  
					 memset(arg, 0 ,sizeof arg);
                     strcat(arg,arr);
                     strcat(arg,arr1);
                     strcat(arg,arr2);
                     strcat(arg,arr3);
			packetbuf_set_datalen(sprintf(packetbuf_dataptr(),"Data aggregated is %s", arg) + 1);
etimer_set(&delay, 0.001 * CLOCK_SECOND);			
}			

			     collect_send(&tc, 15);
			      parent = collect_parent(&tc);
			      if(!rimeaddr_cmp(parent, &oldparent)) {
					if(!rimeaddr_cmp(&oldparent, &rimeaddr_null)) {
					  printf("#L %d 0\n", oldparent.u8[0]);
					}
					if(!rimeaddr_cmp(parent, &rimeaddr_null)) {
					  printf("#L %d 1\n", parent->u8[0]);
					}
					rimeaddr_copy(&oldparent, parent);
			      }
			}
						 
						
			      			

				}
				
			 }


				else
				{
					printf("Sending data cordinates \n");
			      	packetbuf_clear();
			      	packetbuf_set_datalen(sprintf(packetbuf_dataptr(),"%s", line) + 1);

			     collect_send(&tc, 15);
			      parent = collect_parent(&tc);
			      if(!rimeaddr_cmp(parent, &oldparent)) {
					if(!rimeaddr_cmp(&oldparent, &rimeaddr_null)) {
					  printf("#L %d 0\n", oldparent.u8[0]);
					}
					if(!rimeaddr_cmp(parent, &rimeaddr_null)) {
					  printf("#L %d 1\n", parent->u8[0]);
					}
					rimeaddr_copy(&oldparent, parent);
			      }
				}



			 	

			
		}
	/*****************************************************************************/
/*
    if(etimer_expired(&et)) {
      static rimeaddr_t oldparent;
      const rimeaddr_t *parent;

      printf("Sending\n");
      packetbuf_clear();
      packetbuf_set_datalen(sprintf(packetbuf_dataptr(),
				  "%s", "Hello") + 1);*/
  /*  else { 
      static rimeaddr_t oldparent;
      const rimeaddr_t *parent;
	 collect_send(&tc, 15);

      parent = collect_parent(&tc);
      if(!rimeaddr_cmp(parent, &oldparent)) {
        if(!rimeaddr_cmp(&oldparent, &rimeaddr_null)) {
          printf("#L %d 0\n", oldparent.u8[0]);
        }
        if(!rimeaddr_cmp(parent, &rimeaddr_null)) {
          printf("#L %d 1\n", parent->u8[0]);
        }
        rimeaddr_copy(&oldparent, parent);
      }
    }*/
}
//	PROCESS_YIELD();		
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
