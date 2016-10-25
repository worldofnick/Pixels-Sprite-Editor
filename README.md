## CODING GUIDELINES

1. Make sure to `pull` the changes from the `remote` repository to your `local` repository before beginning your implementation. This minimizes the `merge` conflicts and ensures all conflicts are resolved early.
2. There will only be 2 branches at any given time. 
 - The `master` branch will only contain the working codebase at given time (think of it as the `Gold Master` release version).
 - The `developmental` is where we implement our _**next wave of features**_. Once we finish a set number of features, we all test if eveything's in order and `merge  back` the `developmental` branch to `master`. 
 - Then begin implementing the next wave of features in the `developmental` branch again. 
3. As such, `push` all your changes to the `developmental` branch.
4. Use `GitHub`'s **_Issue Tracker_** to keep a list of all the issues and such.

## WEEK 1 WAVE OF FEATURES:
- Basic scalable GUI
- Working `Frame` class (should inherit from `QLabel` and have an associated `QPixmap` to its `pixmap property`. Use `QPainter` to draw on that pixmap and overload `QLabel`'s `paintEvent()` so that calling `update()` on it will update its pixmap. **Example on Slack**).
- Adding multiple frames by pressing `+` button. Should add it **below** the (current) last frame and select it (thus workable in the Workspace).
- Selecting a frame in `Frames panel` should make it the top level frame on the Workspace panel (with all the frames following it stacked below it). Thus, depending on the transparent areas, all the frames below will combine as one image.
- Working `preview window` where its switching frames based on the selected `FPS`.
- Save the project to `.ssp` file format.
- Load project from a `.ssp` file.
- When `quit` is clicked, ask to save before quitting, etc.
- Most of the `menu items`.
- Most of the `tools` (paint with selected color, etc. Except `stamp` tool).

## WEEK 2 WAVE OF FEATURES:
- Enhanced GUI (with all the eye-candy).
- App **_opens with a dialog_** asking for `resolution` of the image, `file name`, etc. Then opens up the main GUI.
- Clicking the _preview_ window will _pop up a new window_ (containing the preview) with zoom controls, etc.
   - Implement those zoom controls.
- Export to `.gif`
- The workspace should `resize` based on the image resolution. If the image is smaller than workspace's resolution, scale the image 2x, 3x, etc.
- Save as a static `Stamp`.
- Save as `SpriteSheet`.
- Other features.
