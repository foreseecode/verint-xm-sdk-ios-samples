//
//  InviteCell.swift
//  AdvancedSample
//

import UIKit

class InviteCell: UICollectionViewCell {
  var didAcceptInvite: (() -> ())?
  
  override func awakeFromNib() {
    super.awakeFromNib()
    
    self.layer.shadowColor = UIColor.gray.cgColor;
    self.layer.shadowOffset = CGSize(width:3.0, height:3.0);
    self.layer.shadowRadius = 2.0;
    self.layer.shadowOpacity = 0.3;
  }
  
  @IBAction func acceptAction(_ sender: Any) {
    self.didAcceptInvite?()
  }
  
}
