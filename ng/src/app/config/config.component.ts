import { Component, Input, OnInit } from '@angular/core';
import { WebsocketService } from '../websocket.service';

@Component({
  selector: 'app-config',
  templateUrl: './config.component.html',
  styleUrls: ['./config.component.css']
})
export class ConfigComponent implements OnInit {
  title = 'Config';
  ssid: string = "";
  password: string = "";
  ipMan: boolean = false;

  ipAddress1: number = 192;
  ipAddress2: number = 168;
  ipAddress3: number = 0;
  ipAddress4: number = 100;

  ipSubnet1: number = 255;
  ipSubnet2: number = 255;
  ipSubnet3: number = 255;
  ipSubnet4: number = 0;

  ipGateway1: number = 192;
  ipGateway2: number = 168;
  ipGateway3: number = 0;
  ipGateway4: number = 1;

  constructor(private websocketService: WebsocketService) { }

  ngOnInit() {
    var that = this;

    this.websocketService.getMessage().subscribe((event) => 
      that.parseMessage(event)
    );
  }

  sendData(){
    this.websocketService.sendData(JSON.stringify({"msgIdent":200,
                                                    "ssid":this.ssid,
                                                    "password":this.password,
                                                    "ipMan":this.ipMan,
                                                    "ipAddress1":this.ipAddress1,
                                                    "ipAddress2":this.ipAddress2,
                                                    "ipAddress3":this.ipAddress3,
                                                    "ipAddress4":this.ipAddress4,
                                                    "ipSubnet1": this.ipSubnet1,
                                                    "ipSubnet2": this.ipSubnet2,
                                                    "ipSubnet3": this.ipSubnet3,
                                                    "ipSubnet4": this.ipSubnet4,
                                                    "ipGateway1": this.ipGateway1,
                                                    "ipGateway2": this.ipGateway2,
                                                    "ipGateway3": this.ipGateway3,
                                                    "ipGateway4": this.ipGateway4,}));
  }

  parseMessage(message){
    if(JSON.parse(message.data).msgIdent == 110){
      //console.log(JSON.parse(message.data)[this.name]);
    }
  }
}
