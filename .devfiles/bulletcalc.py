#!/usr/bin/env python3

import os
import sys
import math

caliberData = {
  "B_408_Ball": [910, -0.00048, 6, 0.05]
}

def degToMil(deg):
  return deg * 17.77777

def traceBullet(caliber, distance, angleTarget, wind, angle):
  global caliberData

  initSpeed = caliberData[caliber][0]
  airFriction = caliberData[caliber][1]
  timeToLive = caliberData[caliber][2]
  simulationStep = caliberData[caliber][3]

  #angle = angle - angleTarget
  #angleTarget = 0

  angle *= math.pi / 180
  angleTarget *= math.pi / 180

  posTarget = [math.cos(angleTarget) * distance, math.sin(angleTarget) * distance]
  pos = [0,0,0]
  velocity = [math.cos(angle) * initSpeed, math.sin(angle) * initSpeed, 0]

  for i in range(int(math.floor(timeToLive / simulationStep))):
    velMag = math.sqrt(velocity[0]**2 + velocity[1]**2 + velocity[2]**2)
    velocity[0] += simulationStep * (velocity[0] * velMag * airFriction) + simulationStep * 0.7 * wind[0]
    velocity[1] += simulationStep * (velocity[1] * velMag * airFriction - 9.81)
    velocity[2] += simulationStep * (velocity[2] + velMag * airFriction) + simulationStep * 0.7 * wind[1]
    pos[0] += velocity[0] * simulationStep
    pos[1] += velocity[1] * simulationStep
    pos[2] += velocity[2] * simulationStep
    if pos[0] >= posTarget[0]:
      break

  return pos[1] - posTarget[1], pos[2]

def calculateSolution(caliber, distance, angleTarget, wind):
  #if traceBullet(caliber, distance, angleTarget, wind, 45) < 0:
  #  return None

  angle1 = angleTarget
  angle2 = 45
  f1, fr = traceBullet(caliber, distance, angleTarget, wind, angle1)

  while abs(f1) > 0.1:
    f2, fr = traceBullet(caliber, distance, angleTarget, wind, angle2)
    temp = angle2 - f2 * (angle2 - angle1) / (f2 - f1)
    angle1 = angle2
    angle2 = temp
    f1 = f2

  up = degToMil(angle1 - angleTarget)
  try:
    right = degToMil(math.atan(fr / distance) / math.pi/180)
  except:
    right = 0

  up = round(up,2)
  right = round(right,2)

  print("RIGHT: {} | UP: {}".format(right, up))

if __name__ == "__main__":
  calculateSolution("B_408_Ball", 1000, 0, (0,0))
