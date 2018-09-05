import { Component, OnInit } from '@angular/core';
import { WebsocketService } from '../websocket.service';

@Component({
  selector: 'app-wifi-bar',
  templateUrl: './wifi-bar.component.html',
  styleUrls: ['./wifi-bar.component.css']
})
export class WifiBarComponent implements OnInit {
  wifiStrength: number = 0;

  constructor(private websocketService: WebsocketService) { }

  ngOnInit() {
    var that = this;

    //this.websocketService.sendData(JSON.stringify({"msgIdent":"0","color":this.name}));
    this.websocketService.getMessage().subscribe((event) => 
      that.parseMessage(event)
    );
  }

  parseMessage(message){
    if(JSON.parse(message.data).msgIdent == 300){
      //console.log(JSON.parse(message.data)['strength']);
      this.wifiStrength=JSON.parse(message.data)['strength'];
    }
  }
}
