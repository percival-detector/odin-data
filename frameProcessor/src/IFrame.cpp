#include "IFrame.h"
#include "IFrameMetaData.h"

namespace FrameProcessor {

/** Base IFrame constructor
 *
 * @param meta-data - frame IFrameMetaData
 * @param image_offset - between start of data memory and image
 */
    IFrame::IFrame(const long long &frame_number, const IFrameMetaData &meta_data, const int &image_offset) :
            frame_number_(frame_number),
            meta_data_(meta_data),
            image_offset_(image_offset) {}

/** Copy constructor;
 * implement as shallow copy
 * @param frame - source frame
 */
    IFrame::IFrame(const IFrame &frame) {
      meta_data_ = frame.meta_data_;
      image_offset_ = frame.image_offset_;
    }

/** Assignment operator;
 * implement as deep copy
 * @param frame - source frame
 * @return IFrame
 */
    IFrame &IFrame::operator=(const IFrame &frame) {
      meta_data_ = frame.meta_data_;
      image_offset_ = frame.image_offset_;
      return *this;
    }

/** Return a void pointer to the image data
 * @ return void poiter to image data
 */
    void *IFrame::get_image_ptr() const {
      return this->get_data_ptr() + image_offset_;
    }

/** Return the frame number
 * @return frame frame number
 */
    long long IFrame::get_frame_number() const {
      return this->frame_number_;
    }

/** Set the frame number
 * @param frame_number - new frame number
 */
    void IFrame::set_frame_number(long long frame_number) {
      this->frame_number_ = frame_number;
    }

/** Return a reference to the MetaData
 * @return reference to meta data
 */
    IFrameMetaData &IFrame::meta_data() {
      return this->meta_data_;
    }

/** Return the MetaData
 * @return frame meta data
 */
    const IFrameMetaData &IFrame::get_meta_data() const {
      return this->meta_data_;
    }

/** Return deep copy of the MetaData
 * @return IFrameMetaDatacopy (deep) of the meta data
 */
    IFrameMetaData IFrame::get_meta_data_copy() const {
      return this->meta_data_;
    }

/** Return the image offset
 * @return offset from beginning of data memory to image data
 * */
    int IFrame::get_image_offset() const {
      return this->image_offset_;
    }

/** Set MetaData
 * @param IFrameMetaData meta_data - new meta data
 * */
    void IFrame::set_meta_data(const IFrameMetaData &meta_data) {
      this->meta_data_ = meta_data;
    }

/** Set the image offset
 * @param offset - new offset
 * */
    void IFrame::set_image_offset(const int &offset) {
      this->image_offset_ = offset;
    }

}
