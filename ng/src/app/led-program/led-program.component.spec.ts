import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { LedProgramComponent } from './led-program.component';

describe('LedProgramComponent', () => {
  let component: LedProgramComponent;
  let fixture: ComponentFixture<LedProgramComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ LedProgramComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(LedProgramComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
