import { Injectable } from '@angular/core';

import { Observable } from 'rxjs/Observable';
import 'rxjs/add/observable/fromEvent';
import { of } from 'rxjs/observable/of';

@Injectable()
export class WebsocketService {
  WebSocket: any; 
  messages: string[] = [];

  constructor() {
    this.init();
  }

  init(){
    var that = this;
    this.WebSocket = new WebSocket("ws://"+location.hostname+":8080");
  }

  sendData(data){
    var failcounter;
    // Wait for socket connection
    if(this.WebSocket.readyState===1){
      this.WebSocket.send(data);
    }else{
      // Maybee deadlock if websocket is not reachable
      var that = this;
      console.log("Server: Websocket not ready");
      setTimeout(function(){
        that.sendData(data);
      },10);
    }
  }

  getMessage(): Observable<Event>{
    return Observable.fromEvent(this.WebSocket,'message');
  }
}
