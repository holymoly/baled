import { Component, OnInit } from '@angular/core';
import { WebsocketService } from '../websocket.service';
import { Observable } from 'rxjs/Observable';

@Component({
  selector: 'app-log-view',
  templateUrl: './log-view.component.html',
  styleUrls: ['./log-view.component.css']
})
export class LogViewComponent implements OnInit {

  messages: string[] =[];

  constructor(private websocketService: WebsocketService) {}

  ngOnInit() {
    var that = this;
    //console.log(this.websocketService.getMessage());
    this.websocketService.getMessage().subscribe((event) => 
      that.pushMessage(event)
    );
  }

  pushMessage(message){
    this.messages.push(message.data);
  }
}
