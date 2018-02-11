import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms'


import { AppComponent } from './app.component';
import { ColorSliderComponent } from './color-slider/color-slider.component';
import { LogViewComponent } from './log-view/log-view.component';
import { WebsocketService } from './websocket.service';


@NgModule({
  declarations: [
    AppComponent,
    ColorSliderComponent,
    LogViewComponent
  ],
  imports: [
    BrowserModule,
    FormsModule
  ],
  providers: [WebsocketService],
  bootstrap: [AppComponent]
})
export class AppModule { }
