<!DOCTYPE html>
<html lang="en">



<head>
  <!-- Required meta tags -->
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <title>Star Admin2 </title>
  <!-- plugins:css -->
  <link rel="stylesheet" href="assets/vendors/feather/feather.css">
  <link rel="stylesheet" href="assets/vendors/mdi/css/materialdesignicons.min.css">
  <link rel="stylesheet" href="assets/vendors/ti-icons/css/themify-icons.css">
  <link rel="stylesheet" href="assets/vendors/typicons/typicons.css">
  <link rel="stylesheet" href="assets/vendors/simple-line-icons/css/simple-line-icons.css">
  <link rel="stylesheet" href="assets/vendors/css/vendor.bundle.base.css">
  <!-- endinject -->
  <!-- Plugin css for this page -->
  <link rel="stylesheet" href="assets/vendors/datatables.net-bs4/dataTables.bootstrap4.css">
  <link rel="stylesheet" type="text/css" href="assets/js/select.dataTables.min.css">
  <!-- End plugin css for this page -->
  <!-- inject:css -->
  <link rel="stylesheet" href="assets/css/vertical-layout-light/style.css">
  <!-- endinject -->
  <link rel="shortcut icon" href="assets/images/favicon.png" />
</head>

<body class="with-welcome-text">
  <div class="container-scroller">
    <div class="row p-0 m-0 proBanner" id="proBanner">
      <div class="col-md-12 p-0 m-0">
        <div class="card-body card-body-padding px-3 d-flex align-items-center justify-content-between">
          <div class="ps-lg-3">
            <div class="d-flex align-items-center justify-content-between">
              <p class="mb-0 font-weight-medium me-3 buy-now-text">Free 24/7 customer support, updates, and more with
                this template!</p>
              <a href="https://www.bootstrapdash.com/product/star-admin-pro/" target="_blank"
                class="btn me-2 buy-now-btn border-0">Buy Now</a>
            </div>
          </div>
          <div class="d-flex align-items-center justify-content-between">
            <a href="https://www.bootstrapdash.com/product/star-admin-pro/"><i class="ti-home me-3 text-white"></i></a>
            <button id="bannerClose" class="btn border-0 p-0">
              <i class="ti-close text-white"></i>
            </button>
          </div>
        </div>
      </div>
    </div>
    <!-- partial:partials/_navbar.html -->
    <nav class="navbar default-layout col-lg-12 col-12 p-0 fixed-top d-flex align-items-top flex-row">
  <div class="text-center navbar-brand-wrapper d-flex align-items-center justify-content-start">
    <div class="me-3">
      <button class="navbar-toggler navbar-toggler align-self-center" type="button" data-bs-toggle="minimize">
        <span class="icon-menu"></span>
      </button>
    </div>
    <div>
      <a class="navbar-brand brand-logo" href="../index.php">
        <img src="../assets/images/logo.svg" alt="logo" />
      </a>
      <a class="navbar-brand brand-logo-mini" href="../index.php">
        <img src="../assets/images/logo-mini.svg" alt="logo" />
      </a>
    </div>
  </div>
  <div class="navbar-menu-wrapper d-flex align-items-top">
    <ul class="navbar-nav">
      <li class="nav-item font-weight-semibold d-none d-lg-block ms-0">
        <h1 class="welcome-text">Welcome to <span class="text-black fw-bold">Todd Carter's Lab Assignment 4</span></h1>
        <h3 class="welcome-sub-text">V0118792<br>cart7982@vandals.uidaho.edu<br></h3></li>
    </ul>

  
    <ul class="navbar-nav ms-auto">
      <li class="nav-item dropdown d-none d-lg-block">
        <a class="nav-link dropdown-bordered dropdown-toggle dropdown-toggle-split" id="messageDropdown" href="#"
          data-bs-toggle="dropdown" aria-expanded="false"> Select Category </a>
        <div class="dropdown-menu dropdown-menu-right navbar-dropdown preview-list pb-0"
          aria-labelledby="messageDropdown">
          <a class="dropdown-item py-3">
            <p class="mb-0 font-weight-medium float-left">Select category</p>
          </a>
          <div class="dropdown-divider"></div>
          <a class="dropdown-item preview-item">
            <div class="preview-item-content flex-grow py-2">
              <p class="preview-subject ellipsis font-weight-medium text-dark">Bootstrap Bundle </p>
              <p class="fw-light small-text mb-0">This is a Bundle featuring 16 unique dashboards</p>
            </div>
          </a>
          <a class="dropdown-item preview-item">
            <div class="preview-item-content flex-grow py-2">
              <p class="preview-subject ellipsis font-weight-medium text-dark">Angular Bundle</p>
              <p class="fw-light small-text mb-0">Everything you’ll ever need for your Angular projects</p>
            </div>
          </a>
          <a class="dropdown-item preview-item">
            <div class="preview-item-content flex-grow py-2">
              <p class="preview-subject ellipsis font-weight-medium text-dark">VUE Bundle</p>
              <p class="fw-light small-text mb-0">Bundle of 6 Premium Vue Admin Dashboard</p>
            </div>
          </a>
          <a class="dropdown-item preview-item">
            <div class="preview-item-content flex-grow py-2">
              <p class="preview-subject ellipsis font-weight-medium text-dark">React Bundle</p>
              <p class="fw-light small-text mb-0">Bundle of 8 Premium React Admin Dashboard</p>
            </div>
          </a>
        </div>
      </li>
      <li class="nav-item d-none d-lg-block">
        <div id="datepicker-popup" class="input-group date datepicker navbar-date-picker">
          <span class="input-group-addon input-group-prepend border-right">
            <span class="icon-calendar input-group-text calendar-icon"></span>
          </span>
          <input type="text" class="form-control">
        </div>
      </li>
      <li class="nav-item">
        <form class="search-form" action="#">
          <i class="icon-search"></i>
          <input type="search" class="form-control" placeholder="Search Here" title="Search here">
        </form>
      </li>
      <li class="nav-item dropdown">
        <a class="nav-link count-indicator" id="notificationDropdown" href="#" data-bs-toggle="dropdown">
          <i class="icon-bell"></i>
          <span class="count"></span>
        </a>
        <div class="dropdown-menu dropdown-menu-right navbar-dropdown preview-list pb-0"
          aria-labelledby="notificationDropdown">
          <a class="dropdown-item py-3 border-bottom">
            <p class="mb-0 font-weight-medium float-left">You have 4 new notifications </p>
            <span class="badge badge-pill badge-primary float-right">View all</span>
          </a>
          <a class="dropdown-item preview-item py-3">
            <div class="preview-thumbnail">
              <i class="mdi mdi-alert m-auto text-primary"></i>
            </div>
            <div class="preview-item-content">
              <h6 class="preview-subject fw-normal text-dark mb-1">Application Error</h6>
              <p class="fw-light small-text mb-0"> Just now </p>
            </div>
          </a>
          <a class="dropdown-item preview-item py-3">
            <div class="preview-thumbnail">
              <i class="mdi mdi-settings m-auto text-primary"></i>
            </div>
            <div class="preview-item-content">
              <h6 class="preview-subject fw-normal text-dark mb-1">Settings</h6>
              <p class="fw-light small-text mb-0"> Private message </p>
            </div>
          </a>
          <a class="dropdown-item preview-item py-3">
            <div class="preview-thumbnail">
              <i class="mdi mdi-airballoon m-auto text-primary"></i>
            </div>
            <div class="preview-item-content">
              <h6 class="preview-subject fw-normal text-dark mb-1">New user registration</h6>
              <p class="fw-light small-text mb-0"> 2 days ago </p>
            </div>
          </a>
        </div>
      </li>
      <li class="nav-item dropdown">
        <a class="nav-link count-indicator" id="countDropdown" href="#" data-bs-toggle="dropdown" aria-expanded="false">
          <i class="icon-mail icon-lg"></i>
        </a>
        <div class="dropdown-menu dropdown-menu-right navbar-dropdown preview-list pb-0"
          aria-labelledby="countDropdown">
          <a class="dropdown-item py-3">
            <p class="mb-0 font-weight-medium float-left">You have 7 unread mails </p>
            <span class="badge badge-pill badge-primary float-right">View all</span>
          </a>
          <div class="dropdown-divider"></div>
          <a class="dropdown-item preview-item">
            <div class="preview-thumbnail">
              <img src="../assets/images/faces/face10.jpg" alt="image" class="img-sm profile-pic">
            </div>
            <div class="preview-item-content flex-grow py-2">
              <p class="preview-subject ellipsis font-weight-medium text-dark">Marian Garner </p>
              <p class="fw-light small-text mb-0"> The meeting is cancelled </p>
            </div>
          </a>
          <a class="dropdown-item preview-item">
            <div class="preview-thumbnail">
              <img src="../assets/images/faces/face12.jpg" alt="image" class="img-sm profile-pic">
            </div>
            <div class="preview-item-content flex-grow py-2">
              <p class="preview-subject ellipsis font-weight-medium text-dark">David Grey </p>
              <p class="fw-light small-text mb-0"> The meeting is cancelled </p>
            </div>
          </a>
          <a class="dropdown-item preview-item">
            <div class="preview-thumbnail">
              <img src="../assets/images/faces/face1.jpg" alt="image" class="img-sm profile-pic">
            </div>
            <div class="preview-item-content flex-grow py-2">
              <p class="preview-subject ellipsis font-weight-medium text-dark">Travis Jenkins </p>
              <p class="fw-light small-text mb-0"> The meeting is cancelled </p>
            </div>
          </a>
        </div>
      </li>
      <li class="nav-item dropdown d-none d-lg-block user-dropdown">
        <a class="nav-link" id="UserDropdown" href="#" data-bs-toggle="dropdown" aria-expanded="false">
          <img class="img-xs rounded-circle" src="../assets/images/faces/face8.jpg" alt="Profile image"> </a>
        <div class="dropdown-menu dropdown-menu-right navbar-dropdown" aria-labelledby="UserDropdown">
          <div class="dropdown-header text-center">
            <img class="img-md rounded-circle" src="../assets/images/faces/face8.jpg" alt="Profile image">
            <p class="mb-1 mt-3 font-weight-semibold">Allen Moreno</p>
            <p class="fw-light text-muted mb-0">allenmoreno@gmail.com</p>
          </div>
          <a class="dropdown-item"><i class="dropdown-item-icon mdi mdi-account-outline text-primary me-2"></i> My
            Profile <span class="badge badge-pill badge-danger">1</span></a>
          <a class="dropdown-item"><i class="dropdown-item-icon mdi mdi-message-text-outline text-primary me-2"></i>
            Messages</a>
          <a class="dropdown-item"><i class="dropdown-item-icon mdi mdi-calendar-check-outline text-primary me-2"></i>
            Activity</a>
          <a class="dropdown-item"><i class="dropdown-item-icon mdi mdi-help-circle-outline text-primary me-2"></i>
            FAQ</a>
          <a class="dropdown-item"><i class="dropdown-item-icon mdi mdi-power text-primary me-2"></i>Sign Out</a>
        </div>
      </li>
    </ul>
    <button class="navbar-toggler navbar-toggler-right d-lg-none align-self-center" type="button"
      data-bs-toggle="offcanvas">
      <span class="mdi mdi-menu"></span>
    </button>
    
  </div>

</nav>

    <!-- partial -->
    <div class="container-fluid page-body-wrapper">
      <!-- partial:partials/_settings-panel.html -->
      <div class="theme-setting-wrapper">
  <div id="settings-trigger"><i class="ti-settings"></i></div>
  <div id="theme-settings" class="settings-panel">
    <i class="settings-close ti-close"></i>
    <p class="settings-heading">SIDEBAR SKINS</p>
    <div class="sidebar-bg-options selected" id="sidebar-light-theme">
      <div class="img-ss rounded-circle bg-light border me-3"></div>Light
    </div>
    <div class="sidebar-bg-options" id="sidebar-dark-theme">
      <div class="img-ss rounded-circle bg-dark border me-3"></div>Dark
    </div>
    <p class="settings-heading mt-2">HEADER SKINS</p>
    <div class="color-tiles mx-0 px-4">
      <div class="tiles success"></div>
      <div class="tiles warning"></div>
      <div class="tiles danger"></div>
      <div class="tiles info"></div>
      <div class="tiles dark"></div>
      <div class="tiles default"></div>
    </div>
  </div>
</div>
<div id="right-sidebar" class="settings-panel">
  <i class="settings-close ti-close"></i>
  <ul class="nav nav-tabs border-top" id="setting-panel" role="tablist">
    <li class="nav-item">
      <a class="nav-link active" id="todo-tab" data-bs-toggle="tab" href="#todo-section" role="tab"
        aria-controls="todo-section" aria-expanded="true">TO DO LIST</a>
    </li>
    <li class="nav-item">
      <a class="nav-link" id="chats-tab" data-bs-toggle="tab" href="#chats-section" role="tab"
        aria-controls="chats-section">CHATS</a>
    </li>
  </ul>
  <div class="tab-content" id="setting-content">
    <div class="tab-pane fade show active scroll-wrapper" id="todo-section" role="tabpanel"
      aria-labelledby="todo-section">
      <div class="add-items d-flex px-3 mb-0">
        <form class="form w-100">
          <div class="form-group d-flex">
            <input type="text" class="form-control todo-list-input" placeholder="Add To-do">
            <button type="submit" class="add btn btn-primary todo-list-add-btn" id="add-task">Add</button>
          </div>
        </form>
      </div>
      <div class="list-wrapper px-3">
        <ul class="d-flex flex-column-reverse todo-list">
          <li>
            <div class="form-check">
              <label class="form-check-label">
                <input class="checkbox" type="checkbox">
                Team review meeting at 3.00 PM
              </label>
            </div>
            <i class="remove ti-close"></i>
          </li>
          <li>
            <div class="form-check">
              <label class="form-check-label">
                <input class="checkbox" type="checkbox">
                Prepare for presentation
              </label>
            </div>
            <i class="remove ti-close"></i>
          </li>
          <li>
            <div class="form-check">
              <label class="form-check-label">
                <input class="checkbox" type="checkbox">
                Resolve all the low priority tickets due today
              </label>
            </div>
            <i class="remove ti-close"></i>
          </li>
          <li class="completed">
            <div class="form-check">
              <label class="form-check-label">
                <input class="checkbox" type="checkbox" checked>
                Schedule meeting for next week
              </label>
            </div>
            <i class="remove ti-close"></i>
          </li>
          <li class="completed">
            <div class="form-check">
              <label class="form-check-label">
                <input class="checkbox" type="checkbox" checked>
                Project review
              </label>
            </div>
            <i class="remove ti-close"></i>
          </li>
        </ul>
      </div>
      <h4 class="px-3 text-muted mt-5 fw-light mb-0">Events</h4>
      <div class="events pt-4 px-3">
        <div class="wrapper d-flex mb-2">
          <i class="ti-control-record text-primary me-2"></i>
          <span>Feb 11 2018</span>
        </div>
        <p class="mb-0 font-weight-thin text-gray">Creating component page build a js</p>
        <p class="text-gray mb-0">The total number of sessions</p>
      </div>
      <div class="events pt-4 px-3">
        <div class="wrapper d-flex mb-2">
          <i class="ti-control-record text-primary me-2"></i>
          <span>Feb 7 2018</span>
        </div>
        <p class="mb-0 font-weight-thin text-gray">Meeting with Alisa</p>
        <p class="text-gray mb-0 ">Call Sarah Graves</p>
      </div>
    </div>
    <!-- To do section tab ends -->
    <div class="tab-pane fade" id="chats-section" role="tabpanel" aria-labelledby="chats-section">
      <div class="d-flex align-items-center justify-content-between border-bottom">
        <p class="settings-heading border-top-0 mb-3 pl-3 pt-0 border-bottom-0 pb-0">Friends</p>
        <small class="settings-heading border-top-0 mb-3 pt-0 border-bottom-0 pb-0 pr-3 fw-normal">See All</small>
      </div>
      <ul class="chat-list">
        <li class="list active">
          <div class="profile"><img src="../assets/images/faces/face1.jpg" alt="image"><span class="online"></span>
          </div>
          <div class="info">
            <p>Thomas Douglas</p>
            <p>Available</p>
          </div>
          <small class="text-muted my-auto">19 min</small>
        </li>
        <li class="list">
          <div class="profile"><img src="../assets/images/faces/face2.jpg" alt="image"><span class="offline"></span>
          </div>
          <div class="info">
            <div class="wrapper d-flex">
              <p>Catherine</p>
            </div>
            <p>Away</p>
          </div>
          <div class="badge badge-success badge-pill my-auto mx-2">4</div>
          <small class="text-muted my-auto">23 min</small>
        </li>
        <li class="list">
          <div class="profile"><img src="../assets/images/faces/face3.jpg" alt="image"><span class="online"></span>
          </div>
          <div class="info">
            <p>Daniel Russell</p>
            <p>Available</p>
          </div>
          <small class="text-muted my-auto">14 min</small>
        </li>
        <li class="list">
          <div class="profile"><img src="../assets/images/faces/face4.jpg" alt="image"><span class="offline"></span>
          </div>
          <div class="info">
            <p>James Richardson</p>
            <p>Away</p>
          </div>
          <small class="text-muted my-auto">2 min</small>
        </li>
        <li class="list">
          <div class="profile"><img src="../assets/images/faces/face5.jpg" alt="image"><span class="online"></span>
          </div>
          <div class="info">
            <p>Madeline Kennedy</p>
            <p>Available</p>
          </div>
          <small class="text-muted my-auto">5 min</small>
        </li>
        <li class="list">
          <div class="profile"><img src="../assets/images/faces/face6.jpg" alt="image"><span class="online"></span>
          </div>
          <div class="info">
            <p>Sarah Graves</p>
            <p>Available</p>
          </div>
          <small class="text-muted my-auto">47 min</small>
        </li>
      </ul>
    </div>
    <!-- chat tab ends -->
  </div>
</div>
      <!-- partial -->
      <!-- partial:partials/_sidebar.html -->
      <nav class="sidebar sidebar-offcanvas" id="sidebar">
  <ul class="nav">
    <li class="nav-item">
      <a class="nav-link" href="../index.php">
        <i class="mdi mdi-grid-large menu-icon"></i>
        <span class="menu-title">Dashboard</span>
      </a>
    </li>

    <li class="nav-item nav-category">Lab Assignment 4 Pages</li>
    <li class="nav-item">
      <a class="nav-link" data-bs-toggle="collapse" href="#ui-basic" aria-expanded="false" aria-controls="ui-basic">
        <i class="menu-icon mdi mdi-floor-plan"></i>
        <span class="menu-title">Lab Assignment 4 Pages</span>
        <i class="menu-arrow"></i>
      </a>
      <div class="collapse" id="ui-basic">
        <ul class="nav flex-column sub-menu">
          <li class="nav-item"> <a class="nav-link" href="../pages/forms/pets_page.php">Pets Page</a></li>
          <li class="nav-item"> <a class="nav-link" href="../pages/forms/owners_page.php">Owners Page</a></li>
          <li class="nav-item"> <a class="nav-link" href="../pages/forms/owns_page.php">Owns Page</a></li>
          <li class="nav-item"> <a class="nav-link" href="../pages/forms/likes_page.php">Likes Page</a></li>
          <li class="nav-item"> <a class="nav-link" href="../pages/forms/foods_page.php">Foods Page</a></li>
          <li class="nav-item"> <a class="nav-link" href="../pages/forms/purchases_page.php">Purchases Page</a></li>
        </ul>
      </div>
    </li>








    <li class="nav-item nav-category">help</li>
    <li class="nav-item">
      <a class="nav-link" href="/pages/documentation/documentation.html">
        <i class="menu-icon mdi mdi-file-document"></i>
        <span class="menu-title">Documentation</span>
      </a>
    </li>
  </ul>
</nav>
      <!-- partial -->
      <div class="main-panel">
        <div class="content-wrapper">
          <div class="row">
            <div class="col-sm-12">
              <div class="home-tab">
                <div class="d-sm-flex align-items-center justify-content-between border-bottom">
                  <ul class="nav nav-tabs" role="tablist">
                    <li class="nav-item">
                      <a class="nav-link active ps-0" id="pets-tab" data-bs-toggle="tab" href="#pets" role="tab"
                        aria-controls="pets" aria-selected="true">Pets</a>
                    </li>
                    <li class="nav-item">
                      <a class="nav-link" id="owners-tab" data-bs-toggle="tab" href="#owners" role="tab"
                        aria-selected="false">Owners</a>
                    </li>
                    <li class="nav-item">
                      <a class="nav-link" id="owns-tab" data-bs-toggle="tab" href="#owns" role="tab"
                        aria-selected="false">Ownership Info</a>
                    </li>
                    <li class="nav-item">
                      <a class="nav-link border-0" id="foods-tab" data-bs-toggle="tab" href="#foods" role="tab"
                        aria-selected="false">Foods</a>
                    </li>
                    <li class="nav-item">
                      <a class="nav-link border-0" id="purchases-tab" data-bs-toggle="tab" href="#purchases" role="tab"
                        aria-selected="false">Purchases</a>
                    </li>
                  </ul>
                  <div>
                    <div class="btn-wrapper">
                      <a href="#" class="btn btn-otline-dark align-items-center"><i class="icon-share"></i> Share</a>
                      <a href="#" class="btn btn-otline-dark"><i class="icon-printer"></i> Print</a>
                      <a href="#" class="btn btn-primary text-white me-0"><i class="icon-download"></i> Export</a>
                    </div>
                  </div>
                </div>

                <div class="tab-content tab-content-basic">


                      {{-- Maybe turn this into the Pets tab? Content table stuff starts here--}}
                  <div class="tab-pane fade show active" id="pets" role="tabpanel">
                    <div class="row">
                    <div class="col-md-6 grid-margin stretch-card">
                      <div class="card">
                        <div class="card-body">
                          <h4 class="card-title">Pets In The Database</h4>
                          <p class="card-description">
                            This table shows which pets are currently in the database and all of their information.
                          </p>
                                <div class = "card-body">      
                                  <?php
                                  $conn = mysqli_connect("localhost","root","","labassignment4");
                                  $result = mysqli_query($conn,"SELECT * FROM pets LIMIT 50");
                                  $data = $result->fetch_all(MYSQLI_ASSOC);
                                  ?>
                  
                                <div class="table-responsive">
                                <table class="table table-bordered text-start">
                                  <thead class="table-light">
                                  <tr>
                                      <th>Pet ID</th>
                                      <th>Pet Name</th>
                                      <th>Age</th>
                                      <th>Street</th>
                                      <th>City</th>
                                      <th>ZipCode</th>
                                      <th>State</th>
                                      <th>Type of Pet</th>
                                  </tr>
                                </thead>
                                  <?php foreach($data as $row): ?>
                                  <tr>
                                      <td><?= htmlspecialchars($row['PetID']) ?></td>
                                      <td><?= htmlspecialchars($row['Name']) ?></td>
                                      <td><?= htmlspecialchars($row['Age']) ?></td>
                                      <td><?= htmlspecialchars($row['Street']) ?></td>
                                      <td><?= htmlspecialchars($row['City']) ?></td>
                                      <td><?= htmlspecialchars($row['ZipCode']) ?></td>
                                      <td><?= htmlspecialchars($row['State']) ?></td>
                                      <td><?= htmlspecialchars($row['TypeofPet']) ?></td>
                                  </tr>
                                  <?php endforeach ?>
                                  </table> 
                              </div>
              
                              </div>
                            </div>
                          </div>
                          
                          </div>
                        </div>
                      </div>
                      <!-- content-wrapper ends -->


                {{-- Content table stuff starts here--}}
                  <div class="tab-pane fade" id="owners" role="tabpanel">
                    <div class="row">
                    <div class="col-md-6 grid-margin stretch-card">
                      <div class="card">
                        <div class="card-body">

                          <h4 class="card-title">Owners In The Database</h4>
                            <p class="card-description">
                              This table shows which owners are currently in the database and all of their information.
                            </p>
                                  <div class = "card-body">      
                                    <?php
                                    $conn = mysqli_connect("localhost","root","","labassignment4");
                                    $result = mysqli_query($conn,"SELECT * FROM owners LIMIT 50");
                                    $data = $result->fetch_all(MYSQLI_ASSOC);
                                    ?>
                    
                                  <div class="table-responsive">
                                    <table class="table table-bordered text-start">
                                      <thead class="table-light">
                                    <tr>
                                        <th>Owner ID</th>
                                        <th>Last Name</th>
                                        <th>Street</th>
                                        <th>City</th>
                                        <th>ZipCode</th>
                                        <th>State</th>
                                        <th>Age</th>
                                        <th>Annual Income</th>
                                    </tr>
                                  </thead>
                                    <?php foreach($data as $row): ?>
                                    <tr>
                                        <td><?= htmlspecialchars($row['OID']) ?></td>
                                        <td><?= htmlspecialchars($row['LastName']) ?></td>
                                        <td><?= htmlspecialchars($row['Street']) ?></td>
                                        <td><?= htmlspecialchars($row['City']) ?></td>
                                        <td><?= htmlspecialchars($row['ZipCode']) ?></td>
                                        <td><?= htmlspecialchars($row['State']) ?></td>
                                        <td><?= htmlspecialchars($row['Age']) ?></td>
                                        <td><?= htmlspecialchars($row['AnnualIncome']) ?></td>
                                    </tr>
                                    <?php endforeach ?>
                                    </table> 
                                </div>
                
                                </div>
                              </div>
                            </div>
                            
                            </div>
                          </div>
                        </div>
                        <!-- content-wrapper ends -->




                        {{-- ownership Content table stuff starts here--}}
                  <div class="tab-pane fade" id="owns" role="tabpanel">
                    <div class="row">
                    <div class="col-md-6 grid-margin stretch-card">
                      <div class="card">
                        <div class="card-body">
                          <h4 class="card-title">Ownership Information In The Database</h4>
                          <p class="card-description">
                            This table shows the information from the owns table.
                          </p>
                                <div class = "card-body">      
                                  <?php
                                  $conn = mysqli_connect("localhost","root","","labassignment4");
                                  $result = mysqli_query($conn,"SELECT * FROM owns LIMIT 50");
                                  $data = $result->fetch_all(MYSQLI_ASSOC);
                                  ?>
                  
                                <div class="table-responsive">
                                  <table class="table table-bordered text-start">
                                    <thead class="table-light">
                                  <tr>
                                      <th>Pet ID</th>
                                      <th>Year</th>
                                      <th>Owner ID</th>
                                      <th>Pet Age At Ownership</th>
                                      <th>Price Paid</th>
                                  </tr>
                                </thead>
                                  <?php foreach($data as $row): ?>
                                  <tr>
                                      <td><?= htmlspecialchars($row['PetID']) ?></td>
                                      <td><?= htmlspecialchars($row['Year']) ?></td>
                                      <td><?= htmlspecialchars($row['OID']) ?></td>
                                      <td><?= htmlspecialchars($row['PetAgeatOwnership']) ?></td>
                                      <td><?= htmlspecialchars($row['PricePaid']) ?></td>
                                  </tr>
                                  <?php endforeach ?>
                                  </table> 
                                </div>
                
                                </div>
                              </div>
                            </div>
                            
                            </div>
                          </div>
                        </div>
                        <!-- content-wrapper ends -->





                        {{-- Foods Content table stuff starts here--}}
                  <div class="tab-pane fade" id="foods" role="tabpanel">
                    <div class="row">
                    <div class="col-md-6 grid-margin stretch-card">
                      <div class="card">
                        <div class="card-body">
                          <h4 class="card-title">Food Information In The Database</h4>
                          <p class="card-description">
                            This table shows the information from the foods table.
                          </p>
                                <div class = "card-body">      
                                  <?php
                                  $conn = mysqli_connect("localhost","root","","labassignment4");
                                  $result = mysqli_query($conn,"SELECT * FROM foods LIMIT 50");
                                  $data = $result->fetch_all(MYSQLI_ASSOC);
                                  ?>
                  
                                <div class="table-responsive">
                                  <table class="table table-bordered text-start">
                                    <thead class="table-light">
                                  <tr>
                                      <th>Food ID</th>
                                      <th>Name</th>
                                      <th>Brand</th>
                                      <th>Type of Food</th>
                                      <th>Price</th>
                                      <th>Item Weight</th>
                                      <th>Class of Food</th>
                                  </tr>
                                </thead>
                                  <?php foreach($data as $row): ?>
                                  <tr>
                                      <td><?= htmlspecialchars($row['FoodID']) ?></td>
                                      <td><?= htmlspecialchars($row['Name']) ?></td>
                                      <td><?= htmlspecialchars($row['Brand']) ?></td>
                                      <td><?= htmlspecialchars($row['TypeofFood']) ?></td>
                                      <td><?= htmlspecialchars($row['Price']) ?></td>
                                      <td><?= htmlspecialchars($row['ItemWeight']) ?></td>
                                      <td><?= htmlspecialchars($row['ClassofFood']) ?></td>
                                  </tr>
                                  <?php endforeach ?>
                                  </table>
                                </div>
                
                                </div>
                              </div>
                            </div>
                            
                            </div>
                          </div>
                        </div>
                        <!-- content-wrapper ends -->




                        {{-- Purchases Content table stuff starts here--}}
                  <div class="tab-pane fade" id="purchases" role="tabpanel">
                    <div class="row">
                    <div class="col-md-6 grid-margin stretch-card">
                      <div class="card">
                        <div class="card-body">
                          <h4 class="card-title">Purchase Information In The Database</h4>
                          <p class="card-description">
                            This table shows the information from the purchases table.
                          </p>
                                <div class = "card-body">      
                                  <?php
                                  $conn = mysqli_connect("localhost","root","","labassignment4");
                                  $result = mysqli_query($conn,"SELECT * FROM purchases LIMIT 50");
                                  $data = $result->fetch_all(MYSQLI_ASSOC);
                                  ?>
                  
                                <div class="table-responsive">
                                  <table class="table table-bordered text-start">
                                    <thead class="table-light">
                                  <tr>
                                      <th>Owner ID</th>
                                      <th>Food ID</th>
                                      <th>Pet ID</th>
                                      <th>Month</th>
                                      <th>Year</th>
                                      <th>Quantity</th>
                                  </tr>
                                </thead>
                                  <?php foreach($data as $row): ?>
                                  <tr>
                                      <td><?= htmlspecialchars($row['OID']) ?></td>
                                      <td><?= htmlspecialchars($row['FoodID']) ?></td>
                                      <td><?= htmlspecialchars($row['PetID']) ?></td>
                                      <td><?= htmlspecialchars($row['Month']) ?></td>
                                      <td><?= htmlspecialchars($row['Year']) ?></td>
                                      <td><?= htmlspecialchars($row['Quantity']) ?></td>
                                  </tr>
                                  <?php endforeach ?>
                                  </table>
                                </div>
                
                                </div>
                              </div>
                            </div>
                            
                            </div>
                          </div>
                        </div>
                        <!-- content-wrapper ends -->





                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
        <!-- content-wrapper ends -->
        <!-- partial:partials/_footer.html -->
        <footer class="footer">
  <div class="d-sm-flex justify-content-center justify-content-sm-between">
    <span class="text-muted text-center text-sm-left d-block d-sm-inline-block">Premium <a
        href="https://www.bootstrapdash.com/" target="_blank">Bootstrap admin template</a> from BootstrapDash.</span>
    <span class="float-none float-sm-end d-block mt-1 mt-sm-0 text-center">Copyright © 2021. All rights reserved.</span>
  </div>
</footer>
        <!-- partial -->
      </div>
      <!-- main-panel ends -->
    </div>
    <!-- page-body-wrapper ends -->
  </div>
  <!-- container-scroller -->

  <!-- plugins:js -->
  <script src="assets/vendors/js/vendor.bundle.base.js"></script>
  <script src="assets/vendors/bootstrap-datepicker/bootstrap-datepicker.min.js"></script>
  <!-- endinject -->
  <!-- Plugin js for this page -->
  <script src="assets/vendors/chart.js/Chart.min.js"></script>
  <script src="assets/vendors/progressbar.js/progressbar.min.js"></script>
  <!-- End plugin js for this page -->
  <!-- inject:js -->
  <script src="assets/js/off-canvas.js"></script>
  <script src="assets/js/hoverable-collapse.js"></script>
  <script src="assets/js/template.js"></script>
  <script src="assets/js/settings.js"></script>
  <script src="assets/js/todolist.js"></script>
  <!-- endinject -->
  <!-- Custom js for this page-->
  <script src="assets/js/jquery.cookie.js" type="text/javascript"></script>
  <script src="assets/js/dashboard.js"></script>
  <script src="assets/js/proBanner.js"></script>
  <!-- <script src="../../assets/js/Chart.roundedBarCharts.js"></script> -->
  <!-- End custom js for this page-->
</body>

</html>