from PIL import Image

def crop(image_path, coords, saved_location):
    image_obj = Image.open(image_path)
    cropped_image = image_obj.crop(coords)
    cropped_image.save(saved_location)
    cropped_image.show()

if __name__ == '__main__':
    l = 0
    for k in range(20):
        j = 0
        for i in range(20):
            image = 'Dones.png'
            name = "foto"+str(k)+"_"+str(i)+".png"
            crop(image, (j, l, j+80, l+80), name)
            j += 80
        l += 80
