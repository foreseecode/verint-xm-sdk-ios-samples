//
//  Cell.swift
//  AdvancedSample
//

import UIKit

class ProductCell: UICollectionViewCell {
  
  @IBOutlet weak var imageView: UIImageView!
  @IBOutlet weak var labelView: UILabel!
  
  override func awakeFromNib() {
    super.awakeFromNib()
    
    self.layer.shadowColor = UIColor.gray.cgColor;
    self.layer.shadowOffset = CGSize(width:3.0, height:3.0);
    self.layer.shadowRadius = 2.0;
    self.layer.shadowOpacity = 0.3;
  }
  
}
