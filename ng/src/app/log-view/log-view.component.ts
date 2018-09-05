import { Component, OnInit } from '@angular/core';
import { WebsocketService } from '../websocket.service';
import { Observable } from 'rxjs';

@Component({
  selector: 'app-log-view',
  templateUrl: './log-view.component.html',
  styleUrls: ['./log-view.component.css']
})
export class LogViewComponent implements OnInit {
  messages: string[] =[];
  enableLog: boolean = false;

  constructor(private websocketService: WebsocketService) {}

  ngOnInit() {
    var that = this;
    //console.log(this.websocketService.getMessage());
    this.websocketService.getMessage().subscribe((event) => 
      that.pushMessage(event)
    );
  }

  pushMessage(message){
    //only store messages when loggin enabled
    if(this.enableLog){
      this.messages.unshift(message.data);
    }
  }
}
