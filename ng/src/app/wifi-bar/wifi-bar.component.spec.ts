import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { WifiBarComponent } from './wifi-bar.component';

describe('WifiBarComponent', () => {
  let component: WifiBarComponent;
  let fixture: ComponentFixture<WifiBarComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ WifiBarComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(WifiBarComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
