#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """
    Iterate over a list of boxes with keys inside.
    Each box may contain keys to other boxes, a key
    with the same number as the index of a box can
    open that box. Determine if all boxes can be opened.
    """
    if len(boxes) <= 1:
        return True

    pending_boxes = [0]
    opened_boxes = set(pending_boxes)

    while pending_boxes:
        current = pending_boxes.pop()
        for key in boxes[current]:
            if key not in opened_boxes and key < len(boxes):
                opened_boxes.add(key)
                pending_boxes.append(key)

    return len(opened_boxes) == len(boxes)
