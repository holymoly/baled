import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms'
import { RouterModule, Routes } from '@angular/router';


import { AppComponent } from './app.component';
import { ColorSliderComponent } from './color-slider/color-slider.component';
import { LogViewComponent } from './log-view/log-view.component';
import { WebsocketService } from './websocket.service';
import { ConfigComponent } from './config/config.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';
import { ColorComponent } from './color/color.component';
import { NavbarTopComponent } from './navbar-top/navbar-top.component';

const appRoutes: Routes = [
  { path: 'color', component: ColorComponent },
  { path: 'config', component: ConfigComponent },
  { path: '',
    redirectTo: 'color',
    pathMatch: 'full'
  },
  { path: '**', component: PageNotFoundComponent }
];

@NgModule({
  declarations: [
    AppComponent,
    ColorSliderComponent,
    LogViewComponent,
    ConfigComponent,
    PageNotFoundComponent,
    ColorComponent,
    NavbarTopComponent
  ],
  imports: [
    RouterModule.forRoot(
      appRoutes,
      { enableTracing: false } // <-- debugging purposes only
    ),
    BrowserModule,
    FormsModule
  ],
  providers: [WebsocketService],
  bootstrap: [AppComponent]
})
export class AppModule { }
