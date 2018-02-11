import { Component, Input, OnInit} from '@angular/core';
import { WebsocketService } from '../websocket.service';

@Component({
  selector: 'app-color-slider',
  templateUrl: './color-slider.component.html',
  styleUrls: ['./color-slider.component.css']
})
export class ColorSliderComponent implements OnInit { 
  value: number = 20;
  @Input() name: string;

  constructor(private websocketService: WebsocketService) { }

  ngOnInit() {
    var that = this;

    //this.websocketService.sendData(JSON.stringify({"msgIdent":"0","color":this.name}));
    this.websocketService.getMessage().subscribe((event) => 
      that.parseMessage(event)
    );
  }

  sendData(data){
    //console.log(data);
    this.websocketService.sendData(JSON.stringify({"msgIdent":1,"value":data,"color":this.name}));
  }

  parseMessage(message){
    if(JSON.parse(message.data).msgIdent == 100){
      console.log(JSON.parse(message.data)[this.name]);
      this.value=JSON.parse(message.data)[this.name];
    }
  }
}
