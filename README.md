
# Yak Unreal Prototypes (UE 5.4)
## Unreal Engine Game Prototypes


## Splitscreen Prototype:

The splitscreen prototype was to try to create a dynamic splitscreen material that I could manipluate to act like the split screen system in hazelight games (ex: It Takes Two)

Future Work:
  Instead of using a material, to take advantage of the viewport controls and try to use extend the built-in viewport splitscreen controls.

## Sprite Replication Prototype:

### Inital Goal: Given how sprites appear in a 3D space, make the sprite appear where the flat side is always facing within 90 degrees to the camera.

  We achieve this by performing a local rotation on the PaperFlipComponent itself. This creates a problem then of which way is the sprite facing because their character direction would now be wrong. We achieved this by checking angles between desired direction to face and the vector from the camera to the actor. Using this info, we can pick from the four sprite directions which one to display.

### Secondary Goal: Make this work with multiplayer replication.

  With the previous framework in place, we just had to create players and make sure that we do not replicate the PaperFlipComponent, but that we do replicate the component that sets the PaperFlipbook source. We also took advantage of PaperZD's animation blueprints to ensure that the selection of the sprite to render was performed on each client individually.
