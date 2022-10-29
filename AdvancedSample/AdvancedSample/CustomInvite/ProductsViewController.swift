//
//  ProductsViewController.swift
//  AdvancedSample
//

import UIKit
import EXPCore
import EXPPredictive

struct Product {
  let name: String
  let image: String
}

class ProductsViewController: UIViewController, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout, UICollectionViewDataSource {
  
  @IBOutlet weak var gridView: UICollectionView!
  var invited: Bool = false
  
  let products: [Product] = [
    Product(name: "Striped tee", image: "top_0000"),
    Product(name: "Bow-Collar Short Sleeve Blouse", image: "top_0001"),
    Product(name: "Basic button-up", image: "top_0002"),
    Product(name: "Striped ruffle button blouse", image: "top_0003"),
    Product(name: "Bow-hem diamond print blouse", image: "top_0004"),
    Product(name: "Floral crop top", image: "top_0005"),
    Product(name: "Sequined crop top", image: "top_0006"),
    Product(name: "Chiffon tank", image: "top_0007"),
    Product(name: "Cashmere Sweater", image: "sweater")
  ]
  
  override func viewDidLoad() {
    super.viewDidLoad()
    self.gridView.register(UINib.init(nibName:"ProductCell", bundle:nil), forCellWithReuseIdentifier: "ProductCell")
    self.gridView.register(UINib.init(nibName:"InviteCell", bundle:nil), forCellWithReuseIdentifier: "InviteCell")
    self.gridView.alwaysBounceVertical = true
    self.gridView.showsVerticalScrollIndicator = true
    self.gridView.dataSource = self
    self.gridView.delegate = self
    
    EXPPredictive.setInviteHandler(self)
    EXPPredictive.checkIfEligibleForSurvey()
  }
  
  override func viewDidDisappear(_ animated: Bool) {
    super.viewDidDisappear(true)
    
    if self.invited {
      EXPPredictive.customInviteDeclined()
    }
    EXPPredictive.setInviteHandler(nil)
  }
  
  
  @IBAction func closeAction(_ sender: Any) {
    self.dismiss(animated: true, completion: nil)
  }
  
  func numberOfSections(in collectionView: UICollectionView) -> Int {
    return 1
  }
  
  func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
    return CGSize(width: 180, height: 280)
  }
  
  func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
    return self.products.count
  }
  
  func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
    if indexPath.row == 3, self.invited {
      
      let cell: InviteCell = collectionView.dequeueReusableCell(withReuseIdentifier: "InviteCell", for: indexPath) as! InviteCell
      cell.didAcceptInvite = {
        self.inviteAcceptedAction()
      }
      return cell
      
    } else {
      
      let cell: ProductCell = collectionView.dequeueReusableCell(withReuseIdentifier: "ProductCell", for: indexPath) as! ProductCell
      cell.imageView.image = UIImage(named: self.products[indexPath.row].image)
      cell.labelView.text = self.products[indexPath.row].name
      return cell
      
    }
  }
  
  func inviteAcceptedAction() {
    EXPPredictive.customInviteAccepted()
    self.invited = false
  }
}

extension ProductsViewController: EXPInviteHandler {
  func show() {
    self.invited = true
    self.gridView.reloadData()
  }
  
  func hide(withAnimation animate: Bool) {
    
  }
}
