import { Component, OnInit } from '@angular/core';
import { WebsocketService } from '../websocket.service';

@Component({
  selector: 'app-color',
  templateUrl: './color.component.html',
  styleUrls: ['./color.component.css']
})
export class ColorComponent implements OnInit {
  title = 'LED';

  ledModes = 'MANUAL FADE RANDOM'.split(' ');
  ledProgramActive: number = 0;
  
  constructor(private websocketService: WebsocketService) { }

  ngOnInit() {
    var that = this;

    //this.websocketService.sendData(JSON.stringify({"msgIdent":"0","color":this.name}));
    this.websocketService.getMessage().subscribe((event) => 
      that.parseMessage(event)
    );
  }

  sendData(){
    //console.log(this.ledProgramActive);
    this.websocketService.sendData(JSON.stringify({"msgIdent":201,"ledProgram":this.ledProgramActive}));
  }

  parseMessage(message){
    if(JSON.parse(message.data).msgIdent == 100){
      console.log(JSON.parse(message.data)["ledProgram"]);
      this.ledProgramActive=JSON.parse(message.data)["ledProgram"];
    }
  }

}
